#11.42
#a
 library(readxl)
 pcb <- read_excel("~/Downloads/pcb.xls", 
                    +     sheet = "_A2")
 View(pcb)
summary(pcb$pcb)
summary(pcb$pcb52)
summary(pcb$pcb118)
summary(pcb$pcb138)
summary(pcb$pcb180)
boxplot(pcb$pcb, main="PCB")
boxplot(pcb$pcb52, main="PCB52")
boxplot(pcb$pcb118, main="PCB118")
boxplot(pcb$pcb138, main="PCB138")
boxplot(pcb$pcb180, main="PCB180")

#b
cor(pcb$pcb, pcb$pcb52) 
cor(pcb$pcb, pcb$pcb118)
cor(pcb$pcb, pcb$pcb138)
cor(pcb$pcb, pcb$pcb180)
cor(pcb$pcb52, pcb$pcb118)
cor(pcb$pcb52, pcb$pcb138)
cor(pcb$pcb52, pcb$pcb180)
cor(pcb$pcb118, pcb$pcb138)
cor(pcb$pcb118, pcb$pcb180)
cor(pcb$pcb138, pcb$pcb180)
plot(pcb$pcb52, pcb$pcb, main="PCB vs PCB52", xlab="PCB52", ylab="PCB")
plot(pcb$pcb118, pcb$pcb, main="PCB vs PCB118", xlab="PCB118", ylab="PCB")
plot(pcb$pcb138, pcb$pcb, main="PCB vs PCB138", xlab="PCB138", ylab="PCB")
plot(pcb$pcb180, pcb$pcb, main="PCB vs PCB180", xlab="PCB180", ylab="PCB")
plot(pcb$pcb118, pcb$pcb52, main="PCB52 vs PCB118", xlab="PCB118", ylab="PCB52")
plot(pcb$pcb138, pcb$pcb52, main="PCB52 vs PCB138", xlab="PCB138", ylab="PCB52")
plot(pcb$pcb180, pcb$pcb52, main="PCB52 vs PCB180", xlab="PCB180", ylab="PCB52")
plot(pcb$pcb138, pcb$pcb118, main="PCB118 vs PCB138", xlab="PCB138", ylab="PCB118")
plot(pcb$pcb180, pcb$pcb118, main="PCB118 vs PCB180", xlab="PCB180", ylab="PCB118")
plot(pcb$pcb180, pcb$pcb138, main="PCB138 vs PCB180", xlab="PCB180", ylab="PCB138")

#11.43
#b
 subpcb=subset(pcb, select=c("pcb", "pcb52", "pcb118", "pcb138", "pcb180"))
 lm1=lm(pcb~pcb52+pcb118+pcb138+pcb180,data=subpcb)
 summary(lm1)
anova(lm1)

#c
 qqnorm(residuals(lm1))
 plot(lm1, which=2)

#11.44
#a
plot(lm1)

#b
 library(readxl)
 pcb2 <- read_excel("~/Downloads/pcb.xls", 
                     +     sheet = "Sheet1")
 View(pcb2)
 lm1<-lm(pcb~(pcb52+pcb118+pcb138+pcb180), data=pcb2)
 summary(lm1)
plot(lm1)

#11.45
#a
 lm2<-lm(pcb~(pcb52+pcb118+pcb138), data=pcb)
 summary(lm2)

#11.46
#a
 lmteq<-lm(teq~(teqpcb+teqdioxin+teqfuran), data=pcb)
 summary(lmteq)
anova(lmteq)

#11.47
 lmteq2<-lm(teq~(pcb52+pcb118+pcb138+pcb180), data=pcb)
 summary(lmteq2)
summary.aov(lmteq2)
plot(lmteq2)

#11.48
 library(readxl)
 log <- read_excel("~/Downloads/pcb.xls", 
                    +     sheet = "log")
 View(log)
 logs<-subset(log, select=c("log138", "log153", "log180", "log28", "log52", "log126", "log118","logpcb","logteq"))
 View(logs)
 summary(logs)
boxplot(logs)

#11.49
#a
 logs<-subset(log, select=c("pcb", "log138", "log153", "log180", "log28", "log52", "log126", "log118", "logpcb"))
 pairs(logs, pch=".")
 cor(logs)

#11.50
 sublog<-subset(log, select=c("logpcb",  "log138", "log153", "log180", "log28", "log52", "log126", "log118"))
 lmlog<-lm(logpcb~log138+log153+log180+log28+log52+log126+log118,data=sublog)
 summary(lmlog)
anova(lmlog)

#11.51
 sublog=subset(log, select=c("logteq", "logpcb",  "log138", "log153", "log180", "log28", "log52", "log126", "log118"))
 lmlog<-lm(logteq~log138+log153+log180+log28+log52+log126+log118+logpcb,data=sublog)
 summary(lmlog)











