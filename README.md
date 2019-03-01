# DemoRteAutosar
Contains a simple demo of how some of the basic functionality of the AUTOSAR runtime environment may be implemented. 

Cases covered:
  - communication of primitive (int) and complex datatypes (here a fixed length string) locally (e. g. on the same ECU)
    - communication of different ECUs may be realized similarly to complex datatypes, but with functions that communicate over a bus
  - remote procedure calls may be realized through setting an event without using variables
  
For more information take a look at Demo.c
