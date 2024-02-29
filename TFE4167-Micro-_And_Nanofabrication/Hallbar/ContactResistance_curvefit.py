#contact reisistance measurement, calculated by linear regression
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
from scipy.stats import linregress

# Given data, R (ohm) and d (cm)
d_values = np.array([0.05, 0.1, 0.2, 0.35, 0.5])
R_values = np.array([4.73, 4.76, 6.96, 7.12, 9.63])

#linear regression fitted to R(d) = 2*R + B*d

def linear(d, R, B):
    return 2*R + B*d

# Experimental values for w and t
t = 2.5 * 10**-4 #cm
w = 898.5 * 10**-4 #cm, Z value of the contact

# Curve fit
popt, pcov = curve_fit(linear, d_values, R_values)

# Linear regression
#slope, intercept, r_value, p_value, std_err = linregress(R, d)

# Plot
plt.scatter(d_values, R_values, label='Original data')
plt.plot(d_values, linear(d_values, *popt), color="red", label='Curve fit')
plt.xlabel("d (cm)")
plt.ylabel("R (ohm)")
plt.legend()
plt.title("Contact Resistance")

#save the plot
plt.savefig('ContactResistance_curvefit.png')

# Print results
print(popt)

