func <- function() {
  vect <- c()
  i <- 1
  while (i < 100) {
    norm <- rnorm(20,2,3)
    x <- (mean(norm)-2)/sqrt(9/20)
    vect <- c(vect, x)
  }
  plot(vect)
  
}

