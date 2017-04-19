# please refer to http://www.statmethods.net/stats/ 
# The code is written as a part of self learning & stuff like that.. no serious intentions

rm(list=ls())
View(iris)
mydata <- iris
sapply(mydata,class) # Know the type of columns in a dataframe
summary(mydata) # five point summary for all vectors in the dataframe

# Frequency table calculations
attach(mydata)
mytable <- table(mydata$Species,mydata$Sepal.Length) # Species are rows and sepal length is in columns
margin.table(mytable,2) # frequency of columns selected -- similar to count of unqiue values in a column
prop.table(mytable,2) # % of ditribution of column vlaues across the row values

# 3 way frequency table
mytable <- xtabs(~mydata$Species+mydata$Sepal.Length+mydata$Petal.Length)
summary(mytable)

# correlation and covariance
mycordata <- iris[,0:4]
cor(mycordata,use="complete.obs",method = "kendall") # if no y is given it assumes : y =x
cor.test(mycordata$Sepal.Length,mycordata$Sepal.Width)
library(Hmisc)
rcorr(as.matrix(mycordata)) # expects the input to be in matrix data type and outputs covariance and signifance levels with respect to method 

# Parametric VS. Non Parametric
# http://blog.minitab.com/blog/adventures-in-statistics-2/choosing-between-a-nonparametric-test-and-a-parametric-test
# http://keydifferences.com/difference-between-parametric-and-nonparametric-test.html

# On a broad spectrum, parametric test checks for test group means and non parametric tests checks for test group medians
# Parmetric tests have statistical power over non parametric tests, and they assume that sample defines the distribution of population and 
# sample has to meet the minimum data points criteria for pertaining parametric tests
# Non Parametric tests are preferred when data does not show any distribution and skewed ( not normal) and contains outliers which you can't remove
# and fails sample size conditions of parametric tests
# Non parametric tests assume spread is uniform across groups
# http://blog.minitab.com/blog/adventures-in-statistics-2/best-way-to-analyze-likert-item-data:-two-sample-t-test-versus-mann-whitney

##################### Step to follow before doing Test ###################
# 1) Graph and do five num summary on the sample
# 2) Run a normality test (Anderson-Darling), if test p-values > 0.05 -- follows normal distribution

# http://blog.minitab.com/blog/adventures-in-statistics-2/understanding-t-tests-t-values-and-t-distributions
# T tests : T = Variance between groups / Variance within groups
# Part of inferential statistics (can be generalized to population from sample)
# checks if two means are reliably different from each other ( Test and Control)
# Bigger T value means whether there is real reliable difference (or) sample are too sparse to detect some pattern
# P values are actual measure
# 3 types of t test: Independent/Unpaired samples, Paired Sample (Before and After), One Sample (Sample against a hypothetical value)
# Assumes sample is normally distributed, same data points, data points are independent of each other
# Sample Size conditions: One sample (S > 20), Paired Test (S1,S2 > 15)

########## T test procedure ##############
# 1) calculates T value for sample groups  with complete observations(A,B or test,control or A,mu)
# 2) Now, algorithm draws multiple random samples and perform t-tests and store resprective t values to get t-distribution
# 3) Assuming normal distribution, calculates the p value for the obtained T value in first step --  which is P Value


t.test(mydata$Sepal.Length,mydata$Sepal.Width)
t.test(mydata$Sepal.Length,mydata$Sepal.Width,paired=TRUE)
t.test(mydata$Petal.Length,mu=3)


# Mann Whitney Test : NUll hypothesis : Probability that sample from X > sample in Y ~ probability that sample from Y > sample in X
# for independent samples, Mann Whiteny test for paired samples, it is called wilcox test
wilcox.test(mydata$Sepal.Length,mydata$Petal.Length) # sum test (independent samples) -- independent t-test
wilcox.test(mydata$Sepal.Length,mydata$Petal.Length,paired=TRUE) # rank test (dependent samples) -- 2 sample t-test


# linear regression
# http://www.statmethods.net/stats/regression.html
regression <- lm(mydata$Sepal.Length ~ mydata$Petal.Width + mydata$Sepal.Width, data = mydata)
summary(regression) # results
coefficients(regression) # coefficents
confint(regression,level=0.95)
residuals(regression)
View(anova(regression))
influence(regression)

