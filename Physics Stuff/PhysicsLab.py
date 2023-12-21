import os
from matplotlib import pyplot as plt

trainWeight = 10000.0
bullVelocity = 1010.0
bullWeight = 0.453592 # 1 lb = 0.453592kg
totalBullWeight = 600.0
curMomentum = 0.0
totalWork = 0.0
bullInterval = 1.0/60.0
totalTime = 0.0
time_axis = []
vel_axis = []
acc_axis = []

while totalBullWeight > 0:
    # F = (MfVf-MiVi)/t  W = Fd
    velocity = curMomentum / (trainWeight+totalBullWeight)
    acceleration = bullWeight * bullVelocity / (trainWeight+totalBullWeight-bullWeight) / bullInterval
    totalTime += bullInterval
    time_axis.append(totalTime)
    vel_axis.append(velocity)
    acc_axis.append(acceleration)
    totalWork += (bullWeight * bullVelocity/bullInterval)*((velocity*bullInterval)+bullWeight * acceleration * bullInterval * bullInterval / 2)
    totalBullWeight-=bullWeight
    curMomentum += bullWeight * bullVelocity


print("Velocity after one bullet: " + str(bullWeight * bullVelocity/(trainWeight+totalBullWeight-bullWeight)))
print("Final Velocity: " + str(curMomentum / trainWeight))
print("Net work (Through Change in KE): " + str(trainWeight*(curMomentum / trainWeight)*(curMomentum / trainWeight)/2))
print("Net work (Through Sum of Force): " + str(totalWork))
print("Run the program in Terminal to see full result")
flag = input("Type Y to see velocity after each bullet. Otherwise jumps to the graphs: ")
if(flag == 'Y'):
    for i in range(1, len(vel_axis)):
        if(i == 1):
            print("Velocity after " + str(i) + " bullet: " + str(vel_axis[i]))
        else:
            print("Velocity after " + str(i) + " bullets: " + str(vel_axis[i]))
    os.system("pause")
plt.plot(time_axis, vel_axis)
plt.title('Velocity vs. Time')
plt.xlabel('Time (s)')
plt.ylabel('Velocity (m/s)')
plt.tight_layout()
plt.grid(1)
plt.show()
plt.plot(time_axis, acc_axis)
plt.title('Acceleration vs. Time')
plt.xlabel('Time (s)')
plt.ylabel('Acceleration (m/s^2)')
plt.tight_layout()
plt.grid(1)
plt.show()
