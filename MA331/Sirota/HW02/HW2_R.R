pnorm(8.25, mean=8, sd=4.8)
pnorm(8.25, mean=12, sd=7.2)
pnorm(8.25, mean=20, 12)
pnorm(8.25, mean=40, 24)

Error=c(0.0748298,0.2072302,0.1635183,0.09293155)

N=c(20,30,50,100)

plot(Error,N)



mean(srs)
var(srs)

srs=c(rnorm(20, 2, 3))


means<- 1:100

vars<- 1:100

for(i in 1:100)
{
  sam=rnorm(50,2,3)
  means[i]=(mean(sam)-2)/sqrt(9/50)
  vars[i]=(49)*var(sam)/9
}

plot(vars)

s
