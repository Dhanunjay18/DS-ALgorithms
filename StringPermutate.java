import java.util.ArrayList;

public class StringPermutate {
    public static void main(String arg[]){
       String x="abc" ;
       ArrayList<String> o=new ArrayList<>();
       
       recurpermutate(x,0,o);
       for(int i=0;i<o.size();i++){
        // System.out.println(o.get(i));
       }
    
    }
    public static ArrayList<String> recurpermutate(String x,int index,ArrayList<String> o){
        
        if(index==x.length()){
            
            String y="";
            for(int i=0;i<x.length();i++)
            {
                y=y+x.charAt(i);
            }
            // System.out.println(y);
            
        
        return o;
        }
        for(int i=index;i<x.length();i++){
            swap(i,index,x);
            recurpermutate(x,index+1,o);
            swap(i,index,x);
        }
        return o;
        
         

    }
    public static void swap(int p,int q,String x){
        // char t=x.charAt(p);
        // x.replace(x.charAt(p),x.charAt(q));
        // x.replace(x.charAt(q), t);
        // System.out.println(x);

        char[] c = x.toCharArray();

        // Replace with a "swap" function, if desired:
        char temp = c[p];
        c[p] = c[q];
        c[q] = temp;

        System.out.println(c.toString());
        x =  c.toString();
    }
}