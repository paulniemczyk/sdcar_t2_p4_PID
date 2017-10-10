# Author: Paul Niemczyk
Udacity Self-Driving Can Engineer Program
Term 2 Project 4: PID Controller
October 2017


## About PID Variables

The PID controller is a lightweight way to add control.

The controller takes the form of:
u(t) = Kp*e(t) + Ki * {I0_t e(Tau)dTau} + Kd*d(e(t))/dt

where: 

* u(t) is the control signal -- in this case the steering_angle
* The middle term is the convolution of the error term over time [0,t]
* The final term is the derivative of the error

The definitions of the coefficients are as follows:

* Kp --> Proportion control: Identifies how far off the center line the robot will go
* Ki --> Drift control: Corrects for any unnatural drift, like if the car's wheels are slightly aligned left or right
* Kd --> Dampener: Dampens the effect of oscillations as governed by Kp when the robot goes back to center

## Tuning Process

Twiddle was presented as a way to compute PID coefficients.
However, given the code shell provided by this project, it seemed that the best way to tune
would be to do it manually.

I started with Kp = Ki = Kd = 0, and then began to tune the coefficients. 

Beginning with Kp, I set it to -5.0, then when there was too much "whiplash", I tuned it down to -1.0.

Then there was too much oscillation occuring very quickly in the track, so I set Kd = -5.0, which didn't seem to correct the strong Kp.

I tuned down both Kp and Ki incrementally together to achieve the right coefficients... 

## Final Tuning

My final tuning was:

* Kp = -0.1
* Ki = 0
* Kd = -2.0

Note: I did not need Ki because the simulator appears to have no drift; i.e., the car is perfectly aligned to go straight without any bias.


Thank you,
Paul Niemczyk


