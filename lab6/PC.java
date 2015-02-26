public class PC
{
  public static void main(String [] args)
  {
     Buffer b = new Buffer(4);
     Producer p = new Producer(b);
     Consumer c = new Consumer(b);
     p.start();
     c.start();
  }
}
class Buffer {
            private int [] buffer;
            private int count = 0, in = 0, out = 0;
	    Buffer(int size)
            {
                 buffer = new int[size];
            }
 
            public synchronized void insert(int c) {
                 while(count == buffer.length) 
                 {
                      try { wait(); }
                      catch (InterruptedException e) { } 
                      finally { } 
                 } 
                 System.out.println("Producing " + c );
                 buffer[in] = c;	 
                 in = (in + 1)%buffer.length ; 
                 count++; 
                 notify(); 
            }
    	public synchronized int remove() {
                 while (count == 0) 
                 {
                      try { wait(); }
                      catch (InterruptedException e) { } 
                      finally { } 
                 } 
                 int c = buffer[out]; 
                 out = (out + 1)%buffer.length;
                 count--;
                 System.out.println("Consuming " + c ); 
                 notify(); 
                 return c;
            }
      }
class Producer extends Thread {
   private Buffer buf;
     Producer(Buffer b) { buf = b; }
   public void run() {
     for(int i = 0; i < 10; i++) {
        buf.insert((int)(i)); }
   }
}    
class Consumer extends Thread {
   private Buffer buf;
   Consumer(Buffer b) { buf = b; }
   public void run() {
     for(int i = 0; i < 10; i++) {
        buf.remove(); }
   }
}  

