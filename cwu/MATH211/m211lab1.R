source("http://www.openintro.org/stat/data/cdc.R")  

#question 1 
dim(cdc)  

#question 2 
summary(cdc$age)
summary(cdc$height)
table(cdc$gender)
table(cdc$genhlth) 

#question 3
under_23and_smoke <- subset(cdc$smoke100, cdc$age < 23)

#question 4
BMI = (cdc$weight / ((cdc$height)^2)) * 703

#question 5
plot(cdc$weight)
plot(cdc$gender, cdc$weight)

#question 6
mean(cdc$weight)
sd(cdc$weight)
nrow(data.frame(cdc$weight[abs(cdc$weight - mean(cdc$weight)) < sd(cdc$weight)]))/nrow(data.frame(cdc$weight))*100 

#question 7
plot(cdc$weight, cdc$height) 

#question 8
boxplot(cdc$weight~cdc$gender)
tapply(cdc$weight, cdc$gender, summary)
