public class Course {
    private String courseID;
    private String courseName;
    Student[] have;
    Course[] enrolls;
    int maxStudent;
    int courseIndex=0;
    int studentIndex=0;
    public Course(String id,String name,int max){
        courseID=id;
        this.courseName=name;
        maxStudent=max;
        have = new Student[maxStudent];
    }

    public String getID() {
        return courseID;
    }

    public String getName() {
        return courseName;
    }

        public void ShowStudent(){
        for(int i=0;i<studentIndex;i++){
            System.out.println(have[i].getID()+""+have[i].getName()); }
        }

        public void ShowEnroll(){
        for(int i=0;i<courseIndex;i++){
            System.out.println(enrolls[i].getID()+""+enrolls[i].getName()); }
    }
}
