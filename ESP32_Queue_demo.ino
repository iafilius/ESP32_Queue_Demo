/*
    Demo using RTOS queues between tasks within Arduino, and resolve concurrent logging to same target/port
    Queues:
    -Simplex and Duplex
    -Fixed length by value
    -Variabele length(but fixated in demo) by reference
    -show PrintQueue statistischs/high water mark

    Loop:
    -Shows Stack high water mark of started available tasks
    -Shows heap available
*/

#include <esp_task_wdt.h>
#include <esp_int_wdt.h>
#include <core_version.h>

// Use handles to controll/find the tasks afterwards, pointer set with xCreateTask
TaskHandle_t ProducerAndReceiverTask1_Handle = NULL;
TaskHandle_t ProducerAndReceiverTask2_Handle = NULL;
TaskHandle_t PrintTask_Handle = NULL;

// Intertask Queue properties
QueueHandle_t xQueue_Handle = NULL;
#define  xQueue_Depth 20
#define  xQueue_Write_Timeout   portMAX_DELAY   // Block until space in queue comes available
#define  xQueue_Read_Timeout 0    // do not block when nothing is available to read

// Introduce a certain change both Proceducer tasks are going to wait  on eachother, and depending on xQueue_Write_Timeout, it might be forever....
#define IWantToSeeTheDeadlock 0   // No deadlock, both Producer tasks just fill-up the queue to half-way
//#define IWantToSeeTheDeadlock 9   // There will be a deadlock, as both producer tasks want to fill up the queue with more elements then available.



// Printing Queue properties
QueueHandle_t xPrintQueue_Handle = NULL;
#define xMaxStringLength  2048      // 1024 seems to crash snprintf, even if it is serialized with mutexes, that sound like a BUG
#define xPrintQueue_Depth 20
//#define xPrintQueue_Write_Timeout   portMAX_DELAY // tightly coupled, all messages wil be shown, but process waits on printing task
#define xPrintQueue_Write_Timeout_in_Task   0   // losely coupled, not all messages may be shown, no waiting for printing task
#define xPrintQueue_Write_Timeout_in_Loop   portMAX_DELAY   // tightly coupled, all messages will be shown, waiting for printing task
// const TickType_t xPrintQueue_Write_Timeout_in_Task = pdMS_TO_TICKS( 0 );

// value of 0 : Tasks running at full speed, most stressfull for possible thread/task/SMP unsafe functions
// value of 1000 : Tasks running at slow speed, most usefull to see things happening.
//#define ProducerAndReceiverDelay    1000
#define ProducerAndReceiverDelay    0


// Declare a mutex Semaphore Handle which we will use to manage the Serial Port.
// It will be used to ensure only only one Task is accessing this resource at any time.
SemaphoreHandle_t xSerialSemaphore = NULL;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }

  Serial.print("Arduino IDE version: "); Serial.println( ARDUINO);
  Serial.print("ESP32-Arduino version: "); Serial.println(ARDUINO_ESP32_RELEASE);
  Serial.print("ESP-IDF Version: "); Serial.println(ESP.getSdkVersion());
  Serial.print("tskKERNEL_VERSION: "); Serial.println(tskKERNEL_VERSION_NUMBER);

  Serial.println( "Compiled: " __DATE__ ", " __TIME__ ", Compiler: " __VERSION__);
  Serial.print("Compiled for board; ");  Serial.println(ARDUINO_BOARD);
  
  xQueue_Handle = xQueueCreate( xQueue_Depth, sizeof( uint32_t ) );    // duplex IPC between tasks
  xPrintQueue_Handle = xQueueCreate( xPrintQueue_Depth, sizeof( char * ) ); // IPC to print task

  // Semaphores are useful to stop a Task proceeding, where it should be paused to wait,
  // because it is sharing a resource, such as the Serial port.
  // Semaphores should only be used whilst the scheduler is running, but we can set it up here.
  if ( xSerialSemaphore == NULL )  // Check to confirm that the Serial Semaphore has not already been created.
  {
    xSerialSemaphore = xSemaphoreCreateMutex();  // Create a mutex semaphore we will use to manage the Serial Port
    if ( ( xSerialSemaphore ) != NULL )
      xSemaphoreGive( ( xSerialSemaphore ) );  // Make the Serial Port available for use, by "Giving" the Semaphore.
  }



  xTaskCreate(
    PrintTask,       /* Task function. */
    "PrintTask",     /* String with name of task. */
    10000,             /* Stack size in bytes (for ESP32), RTOS standard is word. */
    NULL,              /* Parameter passed as input of the task */
    3,                 /* Priority of the task. */
    &PrintTask_Handle);            /* Task handle. may be NULL*/




  xTaskCreate(
    ProducerAndReceiverTask1,       /* Task function. */
    "PAndRTask1",     /* String with name of task. */
    10000,             /* Stack size in bytes (for ESP32), RTOS standard is word. */
    NULL,              /* Parameter passed as input of the task */
    3,                 /* Priority of the task. */
    &ProducerAndReceiverTask1_Handle);            /* Task handle. may be NULL*/

  xTaskCreate(
    ProducerAndReceiverTask2,       /* Task function. */
    "PAndRTask2",     /* String with name of task. */
    10000,             /* Stack size in bytes (for ESP32), RTOS standard is word. */
    NULL,              /* Parameter passed as input of the task */
    3,                 /* Priority of the task. */
    &ProducerAndReceiverTask2_Handle);            /* Task handle. may be NULL*/

}

void loop() {
  // put your main code here, to run repeatedly:
  char* pcStringToSend;

  // Allocate buffer, to be used by reference in Queue, one time only (mutual exclusive)
  pcStringToSend = (char*)prvGetBuffer( xMaxStringLength );
/*
  snprintf_TS_Wrapper(pcStringToSend, xMaxStringLength, "%s on Core: %d, Heap: %d/%d/%d, Stacks: %s:%d:%s %s:%d:%s %s:%d:%s %s:%d:%s",
                      __FUNCTION__, xPortGetCoreID(),
                      ESP.getFreeHeap(), heap_caps_get_free_size(MALLOC_CAP_8BIT), esp_get_minimum_free_heap_size(),
                      pcTaskGetTaskName(NULL),       uxTaskGetStackHighWaterMark(NULL),       eTaskState_To_String(eTaskGetState(pcTaskGetTaskName(NULL))),
                      pcTaskGetTaskName(ProducerAndReceiverTask1_Handle), uxTaskGetStackHighWaterMark(ProducerAndReceiverTask1_Handle), eTaskState_To_String(eTaskGetState(ProducerAndReceiverTask1_Handle)),
                      pcTaskGetTaskName(ProducerAndReceiverTask2_Handle), uxTaskGetStackHighWaterMark(ProducerAndReceiverTask2_Handle), eTaskState_To_String(eTaskGetState(ProducerAndReceiverTask2_Handle)),
                      pcTaskGetTaskName(PrintTask_Handle), uxTaskGetStackHighWaterMark(PrintTask_Handle), eTaskState_To_String(eTaskGetState(PrintTask_Handle))

                     );
*/
  snprintf_TS_Wrapper(pcStringToSend, xMaxStringLength, "%s on Core: %d, Heap: %d/%d/%d, Stacks: %s:%d:%s %s:%d:%s %s:%d:%s %s:%d:%s",
                      __FUNCTION__, xPortGetCoreID(),
                      ESP.getFreeHeap(), heap_caps_get_free_size(MALLOC_CAP_8BIT), esp_get_minimum_free_heap_size(),
                      pcTaskGetTaskName(NULL),       uxTaskGetStackHighWaterMark(NULL),       eTaskState_To_String(eTaskGetState(xTaskGetCurrentTaskHandle())),
                      pcTaskGetTaskName(ProducerAndReceiverTask1_Handle), uxTaskGetStackHighWaterMark(ProducerAndReceiverTask1_Handle), eTaskState_To_String(eTaskGetState(ProducerAndReceiverTask1_Handle)),
                      pcTaskGetTaskName(ProducerAndReceiverTask2_Handle), uxTaskGetStackHighWaterMark(ProducerAndReceiverTask2_Handle), eTaskState_To_String(eTaskGetState(ProducerAndReceiverTask2_Handle)),
                      pcTaskGetTaskName(PrintTask_Handle), uxTaskGetStackHighWaterMark(PrintTask_Handle), eTaskState_To_String(eTaskGetState(PrintTask_Handle))

                     );

  xQueueSend(xPrintQueue_Handle, &pcStringToSend, xPrintQueue_Write_Timeout_in_Loop);
  delay(1000);

  // eTaskGetState accepts char* from pcTaskGetTaskName ?? how is that possible??
  //eTaskState_To_String(eTaskGetState(pcTaskGetTaskName(NULL))); // loop
  //eTaskState_To_String(eTaskGetState("loop"));   // this should be the same
  //xTaskGetCurrentTaskHandle();
  //xTaskGetHandle("loop");
  
}

void ProducerAndReceiverTask1( void * parameter ) {
  uint32_t DataToSend = 0, DataToReceive;
  //  const TickType_t xBlockTime = pdMS_TO_TICKS( 0 );
  int randomnumber;

  char* pcStringToSend;
  //const size_t xMaxStringLength = 1024;
  //BaseType_t xStringNumber = 0;

  uint32_t xQueue_Full_for_this_Task = 0;

  for (;;) {
    srand (time(NULL)); // rand without some initilization is just terrible predicable
    randomnumber = rand() % (xQueue_Depth / 2 + IWantToSeeTheDeadlock); // Make sure there is a change to overflow the queue (2 tasks filling up on both sides)

    //...
    for (; randomnumber > 0; randomnumber--) { // random burst of #messages
      DataToSend=randomnumber;    // Demo values
      if ( xQueueSend( xQueue_Handle, &DataToSend, xQueue_Write_Timeout ) ) {
        pcStringToSend = (char*)prvGetBuffer( xMaxStringLength );
        snprintf_TS_Wrapper(pcStringToSend, xMaxStringLength, "%s: Sent element[%d] from Queue(%d), Running on core: %d, Waiting messages: %d, Space left: %d", __FUNCTION__, randomnumber, xQueue_Full_for_this_Task, xPortGetCoreID(), uxQueueMessagesWaiting(xQueue_Handle), uxQueueSpacesAvailable(xQueue_Handle) );
        xQueueSend(xPrintQueue_Handle, &pcStringToSend, portMAX_DELAY);
      } // xQueueSent
      else {
        xQueue_Full_for_this_Task++;
        pcStringToSend = (char*)prvGetBuffer( xMaxStringLength );
        snprintf_TS_Wrapper(pcStringToSend, xMaxStringLength, "%s: QUEUE FULL: Sent element[%d] from Queue(%d) Running on core: %d, Waiting messages: %d, Space left: %d", __FUNCTION__, randomnumber, xQueue_Full_for_this_Task, xPortGetCoreID(), uxQueueMessagesWaiting(xQueue_Handle), uxQueueSpacesAvailable(xQueue_Handle) );
        xQueueSend(xPrintQueue_Handle, &pcStringToSend, portMAX_DELAY);
      }
    }

    //...
    while ( xQueueReceive( xQueue_Handle, &DataToReceive, xQueue_Read_Timeout ) ) {
      pcStringToSend = (char*)prvGetBuffer( xMaxStringLength );
      snprintf_TS_Wrapper(pcStringToSend, xMaxStringLength, "%s: Received element (%d) from Queue, Running on core: %d, Waiting messages: %d Space left: %d", __FUNCTION__, DataToReceive, xPortGetCoreID(), uxQueueMessagesWaiting(xQueue_Handle), uxQueueSpacesAvailable(xQueue_Handle) );
      xQueueSend(xPrintQueue_Handle, &pcStringToSend, portMAX_DELAY);
    } // xQueueReceive

    esp_task_wdt_reset();   // Feed the dog for this task
    yield();    // WDT idle task may kick in
    delay(ProducerAndReceiverDelay);
  }
}

void ProducerAndReceiverTask2( void * parameter ) {
  uint32_t DataToSend = 0, DataToReceive;
  //  const TickType_t xBlockTime = pdMS_TO_TICKS( 0 );
  int randomnumber;

  char* pcStringToSend;
  //const size_t xMaxStringLength = 1024;
  //BaseType_t xStringNumber = 0;

  uint32_t xQueue_Full_for_this_Task = 0;

  for (;;) {
    srand (time(NULL)); // rand without some initilization is just terrible predicable
    randomnumber = rand() % (xQueue_Depth / 2 + IWantToSeeTheDeadlock); // Make sure there is a change to overflow the queue (2 tasks filling up on both sides)

    //...
    for (; randomnumber > 0; randomnumber--) { // random burst of #messages
      DataToSend=randomnumber;    // Demo values
      if ( xQueueSend( xQueue_Handle, &DataToSend, xQueue_Write_Timeout ) ) {
        pcStringToSend = (char*)prvGetBuffer( xMaxStringLength );
        snprintf_TS_Wrapper(pcStringToSend, xMaxStringLength, "%s: Sent element[%d] from Queue(%d), Running on core: %d, Waiting messages: %d, Space left: %d", __FUNCTION__, randomnumber, xQueue_Full_for_this_Task, xPortGetCoreID(), uxQueueMessagesWaiting(xQueue_Handle), uxQueueSpacesAvailable(xQueue_Handle) );
        xQueueSend(xPrintQueue_Handle, &pcStringToSend, portMAX_DELAY);
      } // xQueueSent
      else {
        xQueue_Full_for_this_Task++;
        pcStringToSend = (char*)prvGetBuffer( xMaxStringLength );
        snprintf_TS_Wrapper(pcStringToSend, xMaxStringLength, "%s: QUEUE FULL: Sent element[%d] from Queue(%d) Running on core: %d, Waiting messages: %d, Space left: %d", __FUNCTION__, randomnumber, xQueue_Full_for_this_Task, xPortGetCoreID(), uxQueueMessagesWaiting(xQueue_Handle), uxQueueSpacesAvailable(xQueue_Handle) );
        xQueueSend(xPrintQueue_Handle, &pcStringToSend, portMAX_DELAY);
      }
    }

    //...
    while ( xQueueReceive( xQueue_Handle, &DataToReceive, xQueue_Read_Timeout ) ) {
      pcStringToSend = (char*)prvGetBuffer( xMaxStringLength );
      snprintf_TS_Wrapper(pcStringToSend, xMaxStringLength, "%s: Received element (%d) from Queue, Running on core: %d, Waiting messages: %d Space left: %d", __FUNCTION__, DataToReceive, xPortGetCoreID(), uxQueueMessagesWaiting(xQueue_Handle), uxQueueSpacesAvailable(xQueue_Handle) );
      xQueueSend(xPrintQueue_Handle, &pcStringToSend, portMAX_DELAY);
    } // xQueueReceive

    esp_task_wdt_reset();   // Feed the dog for this task
    yield();    // WDT idle task may kick in
    delay(ProducerAndReceiverDelay);
  }
}



void PrintTask( void * parameter ) {
  char *pcReveivedString;
  static uint32_t xPrintQueue_HighWaterMark = 0;
  uint32_t xPrintQueue_currentmessages;

  for (;;) {
    // no need to get a mutex on serial, as this should be the only place written to serial
    //Serial.println();

    // Queue depth usage measurement
    xPrintQueue_currentmessages = uxQueueMessagesWaiting(xPrintQueue_Handle);
    if (xPrintQueue_currentmessages > xPrintQueue_HighWaterMark)
      xPrintQueue_HighWaterMark = xPrintQueue_currentmessages;

    // take message of the the queue, and block until a message comes
    xQueueReceive(xPrintQueue_Handle, &pcReveivedString, portMAX_DELAY);

    // Print queue statistiscs, but beware, these are at time of printing, not of submitting, and may confuse you
    Serial.print(strlen(pcReveivedString)); Serial.print(" ");  // Print String legth, as there seems to be a bug in snprintf whith gets masked while enlarging the string buffer.
    Serial.print("xPrintQueue: ");
    Serial.print(xPrintQueue_currentmessages); Serial.print("/");
    Serial.print(xPrintQueue_HighWaterMark); Serial.print("/");
    Serial.print(xPrintQueue_Depth); Serial.print(": ");

    Serial.print("xQueue: ");
    Serial.print(uxQueueMessagesWaiting(xQueue_Handle)); Serial.print("/");
    Serial.print(xQueue_Depth); Serial.print(": ");


    Serial.println(pcReveivedString);

    // Free used Queue buffer referenced, one time only (mutual exclusive)
    prvReleaseBuffer(pcReveivedString);

    esp_task_wdt_reset();   // Feed the dog for this task
    yield();    // WDT idle task may kick in
    //delay(1);
  }
}


// These Functions are intended to allocate and free memory referenced by queue's (allocated and freed in different tasks)
void* prvGetBuffer(size_t xWantedSize ) {
  return malloc( xWantedSize );
}

void prvReleaseBuffer( void *pv ) {
  free(pv);
}


const char * eTaskState_To_String(eTaskState status) {
  // See eTaskState type definition in task
  switch (status) {
    case 0:
      return ("eRunning");
    case 1:
      return ("eReady");
    case 2:
      return ("eBlocked");
    case 3:
      return ("eSuspended");
    case 4:
      return ("eDeleted");
    default:
      return ("Unknown State");
  }

}



// Wrapper for snprintf whihc prooved not to bee "thread"/task/SMP save
void snprintf_TS_Wrapper (char *buf, size_t buf_size, const char *fmt, ...) {
  va_list va;

 // if (xSemaphoreTake( xSerialSemaphore,  portMAX_DELAY  ) ) {

    va_start (va, fmt);
    vsnprintf (buf, buf_size, fmt, va);
    va_end (va);

//    xSemaphoreGive( xSerialSemaphore );
//  }
}
