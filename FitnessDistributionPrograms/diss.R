a=rnorm(1000, 1, 0.2)
b=rnorm(1000, 2, 0.5)
hist(a, xlim=c(-0.5,4.5),ylim=c(0,2.5), col="red", pro=T, xlab="fitness", main="Distrubución de fitness para dos alelos diferentes")
hist(b, add=T, col=rgb(0, 1, 0, 0.5), pro=T)
