
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;


public class TestSystem {
    public static void main(String[] args) {

        int numberMember = 10;
        int numberFarmA = 5;
        int numberFarmB = 3;
        int numberFarmC = 4;

        Users[] user = new Users[numberMember];
        var a = new LinkedList<Users>();
        user[0] = new Users("000011", "Padungkit", "Purchaser");
        user[1] = new Users("000001", "Somboon", "Seller");
        user[2] = new Users("000002", "Narongkit", "Seller");
        user[3] = new Users("000003", "Bangbuatong", "Seller");
        a.add(user[0]);
        a.add(user[1]);
        a.add(user[2]);
        a.add(user[3]);

        FruitsShop[] admin = new FruitsShop[1];
        admin[0] = new FruitsShop("000000", "Admin", "SuperID");

        FarmA[] farmA = new FarmA[numberFarmA];
        var A = new ArrayList<FarmA>();
        farmA[0] = new FarmA("000101", "Orang     ", 35.0);
        farmA[1] = new FarmA("000102", "Banana    ", 25.0);
        farmA[2] = new FarmA("000103", "Jackfruit ", 15.0);
        farmA[3] = new FarmA("000104", "Rambutan  ", 42.0);
        farmA[4] = new FarmA("000105", "Rose apple", 42.0);
        A.add(farmA[0]);
        A.add(farmA[1]);
        A.add(farmA[2]);
        A.add(farmA[3]);
        A.add(farmA[4]);

        FarmB[] farmB = new FarmB[numberFarmB];
        var B = new ArrayList<FarmB>();
        farmB[0] = new FarmB("000201", "Durain    ", 130.0);
        farmB[1] = new FarmB("000202", "Guava     ", 10.0);
        farmB[2] = new FarmB("000203", "Mango     ", 20.0);
        B.add(farmB[0]);
        B.add(farmB[1]);
        B.add(farmB[2]);


        FarmC[] farmC = new FarmC[numberFarmC];
        var C = new ArrayList<FarmC>();
        farmC[0] = new FarmC("000301", "Strawberry", 100.0);
        farmC[1] = new FarmC("000302", "Apple     ", 39.0);
        farmC[2] = new FarmC("000303", "Grape     ", 89.0);
        farmC[3] = new FarmC("000304", "Cantaloupe", 22.0);
        C.add(farmC[0]);
        C.add(farmC[1]);
        C.add(farmC[2]);
        C.add(farmC[3]);

        admin[0].AddUser(user[0]);
        admin[0].AddUser(user[1]);
        admin[0].AddUser(user[2]);
        admin[0].AddUser(user[3]);
        admin[0].AddFruitsA(farmA[0]);
        admin[0].AddFruitsA(farmA[1]);
        admin[0].AddFruitsA(farmA[2]);
        admin[0].AddFruitsA(farmA[3]);
        admin[0].AddFruitsA(farmA[4]);
        admin[0].AddFruitsB(farmB[0]);
        admin[0].AddFruitsB(farmB[1]);
        admin[0].AddFruitsB(farmB[2]);
        admin[0].AddFruitsC(farmC[0]);
        admin[0].AddFruitsC(farmC[1]);
        admin[0].AddFruitsC(farmC[2]);
        admin[0].AddFruitsC(farmC[3]);
        int i = 0;
        do {
            Scanner myObj = new Scanner(System.in);
            System.out.println("FRUITS SHOP");
            System.out.print("Enter Your ID: ");
            String userName = myObj.nextLine();

            do {
                switch (userName) {
                    case "admin":
                        do {
                            admin[0].ShowUsers();
                            System.out.println("YOU CAN SELECT: ");
                            System.out.println("1 FOR SEE ALL MEMBERS. ");
                            System.out.println("2 FOR SELL FRUITS EACH FARM");
                            System.out.println("3 FOR BACK");
                            System.out.print("ENTER YOUR METHOD: ");
                            char sudo = myObj.next().charAt(0);
                            switch (sudo) {
                                case '1':
                                    System.out.println("YOU HAVE " + a.size() + " MEMBER");
                                    i = 2;
                                    break;
                                case '2':
                                    System.out.println("FARM A HAVE " + A.size() + " FRUITS");
                                    admin[0].ShowFruitsA();
                                    System.out.println("FARM B HAVE " + B.size() + " FRUITS");
                                    admin[0].ShowFruitsB();
                                    System.out.println("FARM C HAVE " + C.size() + " FRUITS");
                                    admin[0].ShowFruitsC();
                                    i = 2;
                                    break;
                                case '3':
                                    i = 1;
                                    break;
                                default:
                                    System.out.println("Worng!!");
                                    i = 2;
                                    break;
                            }
                        } while (i == 2);
                        i = 1;
                        break;
                    case "000011":
                        admin[0].ShowFruitsAll();
                        System.out.println("YOU CAN SELECT: ");
                        System.out.println("1 FOR ADD A FRUIT TO YOUR CART. ");
                        System.out.println("2 FOR CHECK FRUITS IN YOUR CART");
                        System.out.println("3 FOR BUY FRUITS IN YOUR CART");
                        System.out.print("ENTER YOUR METHOD: ");
                        char method = myObj.next().charAt(0);
                        switch (method) {
                            case '1':
                                i = 0;
                                Scanner myObj2 = new Scanner(System.in);
                                System.out.print("ENTER ID FRUITS: ");
                                String fruit = myObj2.nextLine();
                                switch (fruit) {
                                    case "000101":
                                        admin[0].AddFruitsCartA(farmA[0]);
                                        break;
                                    case "000102":
                                        admin[0].AddFruitsCartA(farmA[1]);
                                        break;
                                    case "000103":
                                        admin[0].AddFruitsCartA(farmA[2]);
                                        break;
                                    case "000104":
                                        admin[0].AddFruitsCartA(farmA[3]);
                                        break;
                                    case "000105":
                                        admin[0].AddFruitsCartA(farmA[4]);
                                        break;
                                    case "000201":
                                        admin[0].AddFruitsCartB(farmB[0]);
                                        break;
                                    case "000202":
                                        admin[0].AddFruitsCartB(farmB[1]);
                                        break;
                                    case "000203":
                                        admin[0].AddFruitsCartB(farmB[2]);
                                        break;
                                    case "000301":
                                        admin[0].AddFruitsCartC(farmC[0]);
                                        break;
                                    case "000302":
                                        admin[0].AddFruitsCartC(farmC[1]);
                                        break;
                                    case "000303":
                                        admin[0].AddFruitsCartC(farmC[2]);
                                        break;
                                    case "000304":
                                        admin[0].AddFruitsCartC(farmC[3]);
                                        break;

                                    default:
                                        System.out.println("Worng!! ");
                                        break;

                                }
                                break;
                            case '2':
                                admin[0].ShowFruitsOnCart();
                                break;
                            case '3':
                                admin[0].ShowTotalClash();
                                System.out.print("Do you want pay ?(y/n): ");
                                char method2 = myObj.next().charAt(0);
                                switch (method2) {
                                    case 'y':
                                        i = 1;
                                        System.out.print("Finish");
                                        break;
                                    case 'n':
                                        i = 0;
                                        break;
                                    default:
                                        System.out.println("Worng!! ");
                                }
                                break;

                            default:
                                System.out.println("Worng!! ");
                                i = 1;

                        }
                        break;

                    case "000001":
                        admin[0].DetailFarmA();
                        System.out.print("Do you want Exit ?(y/n): ");
                        char method2 = myObj.next().charAt(0);
                        switch (method2) {
                            case 'y':
                                i = 1;
                                System.out.print("Finish");
                                break;
                            case 'n':
                                i = 0;
                                break;
                            default:
                                System.out.println("Worng!! ");
                        }
                        break;


                    case "000002":
                        admin[0].DetailFarmB();
                        System.out.print("Do you want Exit ?(y/n): ");
                        char method3 = myObj.next().charAt(0);
                        switch (method3) {
                            case 'y':
                                i = 1;
                                System.out.print("Finish");
                                break;
                            case 'n':
                                i = 0;
                                break;
                            default:
                                System.out.println("Worng!! ");
                        }
                        break;

                    case "000003":
                        admin[0].DetailFarmC();
                        System.out.print("Do you want Exit ?(y/n): ");
                        char method4 = myObj.next().charAt(0);
                        switch (method4) {
                            case 'y':
                                i = 1;
                                System.out.print("Finish");
                                break;
                            case 'n':
                                i = 0;
                                break;
                            default:
                                System.out.println("Worng!! ");
                        }
                        break;

                    default:
                        System.out.println("WORNG!!");
                }

            } while (i == 0);
        } while (i == 1);
    }
}
