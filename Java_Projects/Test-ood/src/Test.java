public class Test {
    public static void main(String[] arg) {
        double timeSec = 10.0;
        int hoursePower = 246;
        int vehicleWeight = 4000;
        Engine engine = new Engine();
        engine.setHorsePower(hoursePower);
        Vehicle vehicle = new Vehicle(vehicleWeight, engine);
        System.out.println("Vehicle speed(" + timeSec + " sec)=" + vehicle.getSpeedMph(timeSec) + " mph ");
    }
}
