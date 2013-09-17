#define DEBUG 1

#ifndef COMMON_H_INCLUDE
#define COMMON_H_INCLUDE

#if DEBUG == 1
#define SPrint(x) Serial.print(x)
#define SPrintln(x) Serial.println(x)
#else
#define SPrint(x) (x)
#define SPrintln(x) (x)
#endif

#endif
