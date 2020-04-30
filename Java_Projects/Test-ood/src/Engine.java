public class Engine {
    private int horsePower;

    public void setHorsePower(int horsePower) {
        this.horsePower = horsePower;
    }

    public int getSpeedMph(double timesec, int weightPounds) {
        double v = 2.0 * this.horsePower * 746;
        v = v * timesec * 32.17 / weightPounds;
        return (int) Math.round(Math.sqrt(v) * 0.68);
    }
}
