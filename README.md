# Handwritten-machine-learning-algorithms
Handwritten machine learning algorithms with C++

**1. gradient_descent.cpp**

I used the definition method to calculate the differential of the loss function.I just used a univariate function as an example to program a gradient descent algorithm.

**2. batch_gradient_descent.cpp**

I changed the variable to be optimized into a vector type, which can be passed into a vector of any length, and directly use the derivative loss function to replace the process of differentiating the loss function to reduce the number of iterations when differentiating.

**3. miniBatch_gradient_descent.cpp**

Based on batch gradient descent, the number of samples used in one iteration is changed.

**4. stochastic_gradient_descent.cpp**

Based on mini batch gradient descent, change the number of samples used in one iteration to one.

**5. logistics_regression.cpp**

The sigmoid function is added on the basis of linear regression, and the optimization method uses stochastic gradient descent.