import java.util.*;

public class Person implements Comparable<Person>{
    int id;
    String  name;

    public Person(String Name,int Id){
        id=Id;
        name=Name;
    }
    public String getName(){
        return name;
    }

    public boolean equals(Object otherObject){
        if(this == otherObject) return true;
        if(otherObject == null) return false;
        Person other = (Person) otherObject;
        return Objects.equals(name,other.name)&&id == other.id;
    }
    public int hashCode(){
        return Objects.hash(name,id);
    }
    public int compareTo(Person other){
        int diff = Integer.compare(id,other.id);
        return diff != 0 ? diff:name.compareTo(other.name);
    }

}
