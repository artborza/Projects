import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.*;

public class LinklistTest {
    public static void main(String[] args){
        LinkedList a = new  LinkedList<String>();
        a.add("Amy");
        a.add("Carl");
        a.add("Erica");
        LinkedList b = new LinkedList<String>();
        b.add("Bob");
        b.add("Doug");
        b.add("Frances");

        ListIterator<String> aTter = a.listIterator();
        Iterator<String> bIter = b.iterator();
        while (bIter.hasNext()){
            if(aTter.hasNext()) aTter.next();
            aTter.add(bIter.next());
        }
        System.out.println(a);
    }
}
