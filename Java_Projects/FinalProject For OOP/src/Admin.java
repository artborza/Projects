public class Admin {
    private String ID;
    private String Name;
    private String UserTpye;
    Users[] user;
    int userIndex = 0;
    final int maxUser = 99;

    public Admin(String id, String name, String usertpye) {
        ID = id;
        this.Name = name;
        UserTpye = usertpye;
        user = new Users[maxUser];
    }

    public boolean AddUser(Users newUser) {
        if (userIndex <= maxUser) {
            user[userIndex] = newUser;
            userIndex++;
            return true;
        } else return false;
    }

    public String getID() {
        return ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public String getName() {
        return Name;
    }

    public void setName(String name) {
        Name = name;
    }

    public String getUserTpye() {
        return UserTpye;
    }

    public void setUserTpye(String userTpye) {
        UserTpye = userTpye;
    }
}
