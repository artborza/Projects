public class Users {
    private String ID;
    private String Name;
    private String UserTpye;

    public Users(String id, String name, String usertpye) {
        ID = id;
        Name = name;
        UserTpye = usertpye;
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
