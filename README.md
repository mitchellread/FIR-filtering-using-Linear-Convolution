# Real-Time-Continuous-FIR-filtering
FIR filtering using circular buffer.

For real time signal processing applications with higher sampling interval or lower frequency, the FIR filtering process is carried out sequentially on the received stream of inputs. Thus if a sequential block of memory is utilized, the newest incoming element is added to the end. To make the convolution operation efficient, while implementing the filtering algorithm, the data is stored in a wrap-around fashion and is accessed iteratively with the help of a pointer which first points at the newest sample followed by the immediate older sample. This functionality has been implemented in the code provided above.


For reference, 

input.dat file ->
<p align="center">
<img src="https://user-images.githubusercontent.com/41267752/44882320-d38fad00-ac80-11e8-9563-3a123f5ebefa.jpg" width="400" height="400">


filter.dat file ->
<p align="center">
<img src="https://user-images.githubusercontent.com/41267752/44882322-d38fad00-ac80-11e8-99d4-5f761a4b37e9.jpg" width="400" height="400">


Output file will look something like this->
<p align="center">
<img src="https://user-images.githubusercontent.com/41267752/44882319-d38fad00-ac80-11e8-9814-03c6025a12d4.jpg" width="400" height="400">
