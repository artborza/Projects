public class Vehicle {
    private int weightPounds;
    private Engine engine;

    public Vehicle(int weightPounds, Engine engine) {
        this.weightPounds = weightPounds;
        this.engine = engine;
    }

    public double getSpeedMph(Double timesec) {
        return this.engine.getSpeedMph(timesec, weightPounds);
    }
}
