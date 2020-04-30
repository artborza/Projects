public class FruitsShop {
    private String ID;
    private String Name;
    private String UserType;
    Users[] user;
    FarmA[] fruitsA;
    FarmB[] fruitsB;
    FarmC[] fruitsC;
    FarmA[] CartA;
    FarmB[] CartB;
    FarmC[] CartC;
    int userIndex = 0;
    int fruitsIndexA = 0;
    int fruitsIndexB = 0;
    int fruitsIndexC = 0;
    int cartIndexA = 0;
    int cartIndexB = 0;
    int cartIndexC = 0;
    final int maxUser = 20;
    final int maxFruitsA = 5;
    final int maxFruitsB = 3;
    final int maxFruitsC = 4;
    final int maxCart = 10;

    public FruitsShop(String id, String name, String usertpye) {
        ID = id;
        this.Name = name;
        UserType = usertpye;
        user = new Users[maxUser];
        fruitsA = new FarmA[maxFruitsA];
        fruitsB = new FarmB[maxFruitsB];
        fruitsC = new FarmC[maxFruitsC];
        CartA = new FarmA[maxCart];
        CartB = new FarmB[maxCart];
        CartC = new FarmC[maxCart];
    }

    public FruitsShop() {
    }

    public boolean AddUser(Users newUser) {
        if (userIndex <= maxUser) {
            user[userIndex] = newUser;
            userIndex++;
            return true;
        } else return false;
    }

    public boolean AddFruitsA(FarmA newFruits) {
        if (fruitsIndexA <= maxFruitsA) {
            fruitsA[fruitsIndexA] = newFruits;
            fruitsIndexA++;
            return true;
        } else return false;
    }

    public boolean AddFruitsB(FarmB newFruits) {
        if (fruitsIndexB <= maxFruitsB) {
            fruitsB[fruitsIndexB] = newFruits;
            fruitsIndexB++;
            return true;
        } else return false;
    }

    public boolean AddFruitsC(FarmC newFruits) {
        if (fruitsIndexC <= maxFruitsC) {
            fruitsC[fruitsIndexC] = newFruits;
            fruitsIndexC++;
            return true;
        } else return false;
    }

    public boolean AddFruitsCartA(FarmA newFruits) {
        if (cartIndexA <= maxCart) {
            CartA[cartIndexA] = newFruits;
            cartIndexA++;
            return true;
        } else return false;
    }

    public boolean AddFruitsCartB(FarmB newFruits) {
        if (cartIndexB <= maxCart) {
            CartB[cartIndexB] = newFruits;
            cartIndexB++;
            return true;
        } else return false;
    }

    public boolean AddFruitsCartC(FarmC newFruits) {
        if (cartIndexC <= maxCart) {
            CartC[cartIndexC] = newFruits;
            cartIndexC++;
            return true;
        } else return false;
    }

    public void ShowFruitsOnCart() {
        System.out.println("MY FRUITS ON YOUR CART.");
        Double Result = 0.0;
        Double Result1 = 0.0;
        Double Result2 = 0.0;
        Double Result3 = 0.0;
        for (int i = 0; i < cartIndexA; i++) {
            System.out.println("Name:" + CartA[i].getName() + " " + "Price:" + CartA[i].getPrice() + " Bath/Kg");
            Result1 = +CartA[i].getPrice();
        }
        for (int i = 0; i < cartIndexB; i++) {
            System.out.println("Name:" + CartB[i].getName() + " " + "Price:" + CartB[i].getPrice() + " Bath/Kg");
            Result2 = +CartB[i].getPrice();
        }
        for (int i = 0; i < cartIndexC; i++) {
            System.out.println("Name:" + CartC[i].getName() + " " + "Price:" + CartC[i].getPrice() + " Bath/Kg");
            Result3 = +CartC[i].getPrice();
        }
        Result = Result1 + Result2 + Result3;
        System.out.println("TOTAL PRICE OF FRUITS IN YOUR CART IS : " + Result);
    }

    public void ShowTotalClash() {
        Double Result = 0.0;
        Double Result1 = 0.0;
        Double Result2 = 0.0;
        Double Result3 = 0.0;
        for (int i = 0; i < cartIndexA; i++) {
            CartA[i].getPrice();
            Result1 = +CartA[i].getPrice();
        }
        for (int i = 0; i < cartIndexB; i++) {
            CartB[i].getPrice();
            Result2 = +CartA[i].getPrice();
        }
        for (int i = 0; i < cartIndexC; i++) {
            CartC[i].getPrice();
            Result3 = +CartA[i].getPrice();
        }
        Result = Result1 + Result2 + Result3;
        System.out.println("TOTAL PRICE OF FRUITS IN YOUR CART IS : " + Result);
    }

    public void ShowFruitsA() {
        for (int i = 0; i < fruitsIndexA; i++) {
            System.out.println("ID:" + fruitsA[i].getId() + " " + "Name:" + fruitsA[i].getName() + " " + "Price:" + fruitsA[i].getPrice() + " Bath/Kg");

        }
    }

    public void ShowFruitsB() {
        for (int i = 0; i < fruitsIndexB; i++) {
            System.out.println("ID:" + fruitsB[i].getId() + " " + "Name:" + fruitsB[i].getName() + " " + "Price:" + fruitsB[i].getPrice() + " Bath/Kg");
        }
    }

    public void ShowFruitsC() {
        for (int i = 0; i < fruitsIndexC; i++) {
            System.out.println("ID:" + fruitsC[i].getId() + " " + "Name:" + fruitsC[i].getName() + " " + "Price:" + fruitsC[i].getPrice() + " Bath/Kg");
        }

    }

    public void ShowFruitsAll() {
        System.out.println("MY FRUITS THAT YOU CAN BUY.");
        for (int i = 0; i < fruitsIndexA; i++) {
            System.out.println("ID:" + fruitsA[i].getId() + " " + "Name:" + fruitsA[i].getName() + " " + "Price:" + fruitsA[i].getPrice() + " Bath/Kg");

        }
        for (int i = 0; i < fruitsIndexB; i++) {
            System.out.println("ID:" + fruitsB[i].getId() + " " + "Name:" + fruitsB[i].getName() + " " + "Price:" + fruitsB[i].getPrice() + " Bath/Kg");
        }
        for (int i = 0; i < fruitsIndexC; i++) {
            System.out.println("ID:" + fruitsC[i].getId() + " " + "Name:" + fruitsC[i].getName() + " " + "Price:" + fruitsC[i].getPrice() + " Bath/Kg");
        }
    }

    public void ShowUsers() {
        System.out.println("YOUR MEMBER.");
        for (int i = 0; i < userIndex; i++) {
            System.out.println("ID:" + user[i].getID() + " " + "Name:" + user[i].getName() + " " + "Price:" + user[i].getUserTpye());

        }
    }

    public void DetailFarmA() {
        Double Result = 0.0;
        System.out.println("YOUR FRUITS");
        for (int i = 0; i < fruitsIndexA; i++) {
            System.out.println("ID:" + fruitsA[i].getId() + " " + "Name:" + fruitsA[i].getName() + " " + "Price:" + fruitsA[i].getPrice() + " Bath/Kg");
        }
        System.out.println("SALES HISTORY:");
        for (int i = 0; i < cartIndexA; i++) {
            System.out.println("Name:" + CartA[i].getName() + " " + "Price:" + CartA[i].getPrice() + " Bath/Kg");
            Result = +CartA[i].getPrice();
        }
        System.out.println("TOLTAL INCOME:" + Result + " Bath");
    }

    public void DetailFarmB() {
        Double Result = 0.0;
        System.out.println("YOUR FRUITS");
        for (int i = 0; i < fruitsIndexB; i++) {
            System.out.println("ID:" + fruitsB[i].getId() + " " + "Name:" + fruitsB[i].getName() + " " + "Price:" + fruitsB[i].getPrice() + " Bath/Kg");
        }
        System.out.println("SALES HISTORY:");
        for (int i = 0; i < cartIndexB; i++) {
            System.out.println("Name:" + CartB[i].getName() + " " + "Price:" + CartB[i].getPrice() + " Bath/Kg");
            Result = +CartB[i].getPrice();
        }
        System.out.println("TOLTAL INCOME:" + Result + " Bath");
    }

    public void DetailFarmC() {
        Double Result = 0.0;
        System.out.println("YOUR FRUITS");
        for (int i = 0; i < fruitsIndexC; i++) {
            System.out.println("ID:" + fruitsC[i].getId() + " " + "Name:" + fruitsC[i].getName() + " " + "Price:" + fruitsC[i].getPrice() + " Bath/Kg");
        }
        System.out.println("SALES HISTORY:");
        for (int i = 0; i < cartIndexC; i++) {
            System.out.println("Name:" + CartC[i].getName() + " " + "Price:" + CartC[i].getPrice() + " Bath/Kg");
            Result = +CartC[i].getPrice();
        }
        System.out.println("TOLTAL INCOME:" + Result + " Bath");
    }

    public String getId() {
        return ID;
    }

    public void setId(String ID) {
        this.ID = ID;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public String getUserTpye() {
        return UserType;
    }

    public void setUserTpye(String userTpye) {
        UserType = userTpye;
    }
}
