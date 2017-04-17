# please refer to http://www.statmethods.net/stats/correlations.html

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

# T tests : T = Variance between groups / Variance within groups
# Part of inferential statistics (can be generalized to population from sample)
# checks if two means are reliably different from each other ( Test and Control)
# Bigger T value means whether there is real reliable difference (or) sample are too sparse to detect some pattern
# P values are actual measure
# 3 types of t test: Independent/Unpaired samples, Paired Sample (Before and After), One Sample (Sample against a hypothetical value)
# Assumes sample is normally distributed, same data points, data points are independent of each other
t.test(mydata$Sepal.Length,mydata$Sepal.Width)
t.test(mydata$Sepal.Length,mydata$Sepal.Width,paired=TRUE)
t.test(mydata$Petal.Length,mu=3)

