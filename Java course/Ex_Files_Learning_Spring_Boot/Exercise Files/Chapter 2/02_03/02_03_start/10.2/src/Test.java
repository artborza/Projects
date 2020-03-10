public class Test {
    public static void main(String[] args) {
        var courses = new Course[3];
        courses[0] = new Course("618445", "Object Orient", 50);
        courses[1] = new Course("618454", "Embedded System", 60);
        courses[2] = new Course("618495", "ECS Project", 15);

        Student[] students = new Student[2];
        students[0] = new Student("60101", "Niti");
        students[1] = new Student("60110", "Wut");

        students[0].AddCourse(courses[0]);
        students[0].AddCourse(courses[1]);
        students[1].AddCourse(courses[0]);
        students[1].AddCourse(courses[1]);
        students[1].AddCourse(courses[2]);

        students[0].AddStudent(students[0]);
        students[0].AddStudent(students[1]);
        students[1].AddStudent(students[0]);
        students[1].AddStudent(students[1]);
        students[2].AddStudent(students[1]);

        students[0].ShowEnroll();
        courses[0].ShowStudent();

    }
}
