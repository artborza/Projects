import java.util.Comparator;
import java.util.TreeSet;

public class PersonTest {
    public static void main(String[] args){
        TreeSet parts = new TreeSet<Person>();
        parts.add(new Person("Aof",12));
        parts.add(new Person("Non",25));
        parts.add(new Person("pae",00));
        System.out.println(parts);

        TreeSet sortByName = new TreeSet<Person>(Comparator.comparing(Person::getName));

        sortByName.addAll(parts);
        System.out.println(sortByName);
    }
}
