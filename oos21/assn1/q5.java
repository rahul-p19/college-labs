class Complex{
	double real, imag;

	Complex(){
		real=0;
		imag=0;
	}

	Complex(double r){
		real=r;
		imag=0;
	}

	Complex(double r, double i){
		real=r;
		imag=i;
	}
	void add(Complex a){
		System.out.println("Sum: ");	
		System.out.println((real+a.real)+" + "+(imag+a.imag)+"i");
	}
	void multiply(Complex a){
		System.out.println("Product: "); 
		System.out.println(((real*a.real)-(imag*a.imag))+" + "+((imag*a.real)+(real*a.imag))+"i");
	}
	public static void main(String args[]){
		Complex a = new Complex(3,2);
		Complex b = new Complex(4,-2);
		a.add(b);
		a.multiply(b);
	}
}
