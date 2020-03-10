public class Gen<T> {
    T obj;
    Gen(T obj){
        this.obj = obj;
    }
    public T getObject(){
        return this.obj;
    }
}
