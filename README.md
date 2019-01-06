# ESP32_Queue_Demo
Concept demo of using RTOS queues within Arduino IDE, using of inter task communicating and solving multi task printing to one port issue.

Queues:
- Simplex and Duplex
- Fixed length by value
- Variabele length(but fixated in demo) by reference
- show PrintQueue statistischs/high water mark

Loop:
- Shows Stack high water mark of started available tasks
- Shows heap available

Demo output with `#define IWantToSeeTheDeadlock 0 `
```
Arduino IDE version: 10808
ESP32-Arduino version: 1_0_1_RC2
ESP-IDF Version: v3.3-beta1-44-gda2116f55-dirty
tskKERNEL_VERSION: V8.2.0
Compiled: Jan  6 2019, 13:07:21, Compiler: 5.2.0
Compiled for board; ESP32_DEV
112 xPrintQueue: 0/0/20: xQueue: 4/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
112 xPrintQueue: 20/20/20: xQueue: 2/20: ProducerAndReceiverTask1: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 2, Space left: 18
112 xPrintQueue: 20/20/20: xQueue: 3/20: ProducerAndReceiverTask1: Sent element[2] from Queue(0), Running on core: 0, Waiting messages: 3, Space left: 17
112 xPrintQueue: 20/20/20: xQueue: 2/20: ProducerAndReceiverTask1: Sent element[1] from Queue(0), Running on core: 0, Waiting messages: 4, Space left: 16
113 xPrintQueue: 20/20/20: xQueue: 3/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 0, Waiting messages: 3 Space left: 17
113 xPrintQueue: 20/20/20: xQueue: 2/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 0, Waiting messages: 2 Space left: 18
113 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 0, Waiting messages: 1 Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 0, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
112 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 0, Waiting messages: 2, Space left: 18
113 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Received element (2) from Queue, Running on core: 0, Waiting messages: 1 Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask2: Received element (1) from Queue, Running on core: 0, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
112 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 0, Waiting messages: 2, Space left: 18
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 0, Waiting messages: 3, Space left: 17
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask2: Received element (3) from Queue, Running on core: 0, Waiting messages: 2 Space left: 18
113 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Received element (2) from Queue, Running on core: 0, Waiting messages: 1 Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask2: Received element (1) from Queue, Running on core: 0, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask1: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
112 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Sent element[2] from Queue(0), Running on core: 0, Waiting messages: 2, Space left: 18
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask1: Sent element[1] from Queue(0), Running on core: 0, Waiting messages: 3, Space left: 17
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 0, Waiting messages: 2 Space left: 18
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 3, Space left: 17
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 2 Space left: 18
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 3, Space left: 17
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 2 Space left: 18
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 3, Space left: 17
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 2 Space left: 18
113 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Received element (2) from Queue, Running on core: 1, Waiting messages: 1 Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[8] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (8) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[7] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (7) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[6] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (6) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[5] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (5) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[4] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (4) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[8] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (8) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[7] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (7) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[6] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (6) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[5] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (5) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[4] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (4) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[8] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (8) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[7] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (7) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[6] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (6) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[5] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (5) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[4] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (4) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[8] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (8) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[7] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (7) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[6] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (6) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[5] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (5) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[4] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (4) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[2] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (2) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[1] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (1) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[8] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (8) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[7] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (7) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[6] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (6) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[5] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (5) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[4] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (4) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20
112 xPrintQueue: 20/20/20: xQueue: 1/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 1, Waiting messages: 1, Space left: 19
113 xPrintQueue: 20/20/20: xQueue: 0/20: ProducerAndReceiverTask1: Received element (3) from Queue, Running on core: 1, Waiting messages: 0 Space left: 20

```


Demo output with '#define IWantToSeeTheDeadlock 9'
```
ESP32-Arduino version: 1_0_1_RC2
ESP-IDF Version: v3.3-beta1-44-gda2116f55-dirty
tskKERNEL_VERSION: V8.2.0
Compiled: Jan  6 2019, 12:55:54, Compiler: 5.2.0
Compiled for board; ESP32_DEV
113 xPrintQueue: 0/0/20: xQueue: 20/20: ProducerAndReceiverTask1: Sent element[13] from Queue(0), Running on core: 0, Waiting messages: 1, Space left: 18
113 xPrintQueue: 20/20/20: xQueue: 20/20: ProducerAndReceiverTask2: Sent element[13] from Queue(0), Running on core: 1, Waiting messages: 2, Space left: 18
113 xPrintQueue: 19/20/20: xQueue: 20/20: ProducerAndReceiverTask1: Sent element[12] from Queue(0), Running on core: 0, Waiting messages: 4, Space left: 16
113 xPrintQueue: 18/20/20: xQueue: 20/20: ProducerAndReceiverTask2: Sent element[12] from Queue(0), Running on core: 1, Waiting messages: 4, Space left: 16
113 xPrintQueue: 17/20/20: xQueue: 20/20: ProducerAndReceiverTask1: Sent element[11] from Queue(0), Running on core: 0, Waiting messages: 6, Space left: 14
113 xPrintQueue: 16/20/20: xQueue: 20/20: ProducerAndReceiverTask2: Sent element[11] from Queue(0), Running on core: 1, Waiting messages: 6, Space left: 14
113 xPrintQueue: 15/20/20: xQueue: 20/20: ProducerAndReceiverTask1: Sent element[10] from Queue(0), Running on core: 0, Waiting messages: 8, Space left: 12
113 xPrintQueue: 14/20/20: xQueue: 20/20: ProducerAndReceiverTask2: Sent element[10] from Queue(0), Running on core: 1, Waiting messages: 8, Space left: 12
113 xPrintQueue: 13/20/20: xQueue: 20/20: ProducerAndReceiverTask1: Sent element[9] from Queue(0), Running on core: 0, Waiting messages: 10, Space left: 10
113 xPrintQueue: 12/20/20: xQueue: 20/20: ProducerAndReceiverTask2: Sent element[9] from Queue(0), Running on core: 1, Waiting messages: 10, Space left: 10
112 xPrintQueue: 11/20/20: xQueue: 20/20: ProducerAndReceiverTask1: Sent element[8] from Queue(0), Running on core: 0, Waiting messages: 12, Space left: 8
112 xPrintQueue: 10/20/20: xQueue: 20/20: ProducerAndReceiverTask2: Sent element[8] from Queue(0), Running on core: 1, Waiting messages: 12, Space left: 8
112 xPrintQueue: 9/20/20: xQueue: 20/20: ProducerAndReceiverTask1: Sent element[7] from Queue(0), Running on core: 0, Waiting messages: 14, Space left: 6
112 xPrintQueue: 8/20/20: xQueue: 20/20: ProducerAndReceiverTask2: Sent element[7] from Queue(0), Running on core: 1, Waiting messages: 14, Space left: 6
112 xPrintQueue: 7/20/20: xQueue: 20/20: ProducerAndReceiverTask1: Sent element[6] from Queue(0), Running on core: 0, Waiting messages: 16, Space left: 4
112 xPrintQueue: 6/20/20: xQueue: 20/20: ProducerAndReceiverTask2: Sent element[6] from Queue(0), Running on core: 1, Waiting messages: 16, Space left: 4
112 xPrintQueue: 5/20/20: xQueue: 20/20: ProducerAndReceiverTask2: Sent element[5] from Queue(0), Running on core: 1, Waiting messages: 18, Space left: 2
112 xPrintQueue: 4/20/20: xQueue: 20/20: ProducerAndReceiverTask2: Sent element[4] from Queue(0), Running on core: 1, Waiting messages: 19, Space left: 1
112 xPrintQueue: 3/20/20: xQueue: 20/20: ProducerAndReceiverTask2: Sent element[3] from Queue(0), Running on core: 1, Waiting messages: 20, Space left: 0
112 xPrintQueue: 2/20/20: xQueue: 20/20: ProducerAndReceiverTask1: Sent element[5] from Queue(0), Running on core: 1, Waiting messages: 20, Space left: 0
149 xPrintQueue: 1/20/20: xQueue: 20/20: loop on Core: 1, Heap: 300748/215716/214068, Stacks: loopTask:7540:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9496:eRunning
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked
149 xPrintQueue: 0/20/20: xQueue: 20/20: loop on Core: 1, Heap: 342028/256996/214068, Stacks: loopTask:6744:eRunning PAndRTask1:8668:eBlocked PAndRTask2:8668:eBlocked PrintTask:9272:eBlocked

```
