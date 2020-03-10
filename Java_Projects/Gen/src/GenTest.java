public class GenTest {
    public static void main(String[] args){
        Gen <Double> dObj = new Gen<Double>(1.0);
        System.out.println(dObj.getObject());

        Gen <String> sObj = new Gen<String>("Hello");
        System.out.println(sObj.getObject());
    }
}
