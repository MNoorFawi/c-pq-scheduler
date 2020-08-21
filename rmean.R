args <- commandArgs(trailingOnly = TRUE)
file <- args[1]
numbers <- as.numeric(read.table(file, header = FALSE, stringsAsFactors = FALSE)[, 1])
print(paste0("\n\t", "Average of number list in R is: ", mean(numbers), "\n"))