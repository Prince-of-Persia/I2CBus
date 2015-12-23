# I2CBus
Communication between two or more micro controllers/devices 

  This is only for initialising the I2CBus, Send and receive data. 
  The programe makes use of Wire Library 
  

# Master
It manages the Bus and request information from the slave/s devices 
It unpacks the data received from a "slave" into an array. Which then can be assigned to different variables to execute the relevant code.

# Slave 
In the current sketch:
The Slave microcontroller connects to the bus with the address #8.
It reads from sensors attached and packs the information collected in an array. Upon request of the Master microcontroller, it sends the array via bus.


More sensors and devices can be added for further expansion.

