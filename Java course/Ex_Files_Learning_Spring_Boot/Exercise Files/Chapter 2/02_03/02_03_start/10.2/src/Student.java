public class Student {
    private String ID;
    private String name;
    Course[] entrolls;
    Student[] have;
    final int maxCourse=10;
    int maxStudent;
    int studentIndex=0;
    int courseIndex=0;
    Course[] enrolls;
    public Student(String id,String name){
        ID=id;
        this.name = name;
        entrolls = new Course[maxCourse];
    }

    public String getID() {
        return ID;
    }

    public String getName() {
        return name;
    }

    public void ShowEnroll() {
    }
    public  boolean AddStudent(Student newStudent){
        if (studentIndex <= maxStudent){
            have[studentIndex] = newStudent;
            studentIndex++;
            return true;
        }else return false; }

    public  boolean AddCourse(Course newCourse){
        if (courseIndex <= maxCourse){
            enrolls[courseIndex] = newCourse;
            courseIndex++;
            return true;
        }else return false; }
}
