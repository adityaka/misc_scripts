package helloworld

println "Hello World"

// Comments
/* multiline 
comment
*/

def a = 5
def b = 2
println "Arithmetic operators"
println a + "+" + b + "=" + (a+b)
println a + "-" + b + "=" + (a-b)
println a + "*" + b + "=" + (a*b)
println a + "/" + b + "=" + (a/b)
println a + "**" + b + "=" + (a**b)
println a + "%" + b + "=" + (a%b)
println "Pre Post and other increment operators"
println "Initial value of a "
println a + "++" + "=" + (a++)
println  "++" + a + "=" + (++a)
println a + "--" + "=" + (a--)
println "--" + a + "=" + (a--)
println a + "+=" + b + "=" + (a+=b)
println a + "-=" + b + "=" + (a-=b)
println a + "*=" + b + "=" + (a*=b)
println a + "/=" + b + "=" + (a/=b)

// Loops and conditions

def listLimit = 500 

println "Prime number between first 500 numbers"

if (a > b) {
    println a + " is greater than " + b
} else {
    println a + " is less than " + b
}

for (def i = 1; i <= listLimit; i++) {
    def isPrime = true;
   
    for (def j = 1; j < i; j++ ) {
        
        if (i % j == 0 && j > 1 && i > 3 ) {
            isPrime = false;
            break;
        }
    }
    if (isPrime) {
        print i + " "
    }
}
println ""






