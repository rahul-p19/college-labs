import java.util.Scanner;
class Room{
	double height, width, breadth;
	Room(double h, double w, double b){
		height=h;
		width=w;
		breadth=b;
	}

	double volume(){
		return height*width*breadth;
	}
}

class RoomDemo{
	public static void main(String args[]){
	Scanner sc = new Scanner(System.in);
	System.out.print("Enter the height: ");
	double h,w,b;
	h = sc.nextDouble();	
	System.out.print("Enter the width: ");
	w = sc.nextDouble();	
	System.out.print("Enter the breadth: ");
	b = sc.nextDouble();	
	Room r1 = new Room(h,w,b);
	System.out.println("Volume of the room: "+r1.volume());
	}
}
