/**
* A very basic Student class that inherits from, or extends,
*  the basic Person class
*
* @author 	Chane Li
* @version	1.0
*/

public class Student extends Person
{
	//Private Properties of an Student object
	//These are in addition to the properties inherited from the Person class
	private long studentNumber;
	private String chooseMajor;
	private String collegeDepartment;
	private double gpa;
	
	/**
	* No argument constructor that creates a generic Student object
	*/
	public Student()
	{
		super();

		// set the default value for Student class
		studentNumber = 2001039943;
		chooseMajor = "Programming";
		collegeDepartment = "CIT";
		gpa = 4.0;
	}
	
	/**
	* A constructor with the most common values for an Student object supplied
	*
	* @param fN				The first or given name of the new Student object
	* @param lN				The last of family name of the new Student object
	* @param sex			The gender or sex of the new Student object (valid values are "male", "female", and "unspecified")
	* @param age			The age in years of the new Student object (age must be a positive integer less than 128)
	* @param stuNumber		The unique student number of this Student object.  Student numbers must be 10 digit positive long type
	*						that start with a non-zero long type.
	* @param gpa			The gpa in the new Student Object.  All GPA must be in the range of 0.0 ~ 4.0.
	*
	* @throws IllegalArgumentException		Thrown if the passed in gender is not "male", "female", or "unspecified";
	*										or if the age is negative; or if the student number is not a non-negative
	*										10 digit long type starting with a non-zero long type; or if the gpa is less than zero
	* 
	*/
	public Student(String fN, String lN, String sex, byte age, long stuNumber, double gpa)
	{
		//In this case I want to call the (String, String, String, byte) version of the Person constructor so
		//  I use super (indicating the parent superclass) with the correct arguments
		//Note:  I still documented the parameters passed into this method even though I am "forwarding" them
		//  Because the implementation is not known to the consumer, we need to tell them what this method needs
		super(fN, lN, sex, age);
		if (stuNumber >= 1000000000L && stuNumber <= 9990000000L)
		{
			studentNumber = stuNumber;
		}
		else
		{
			throw new IllegalArgumentException("All Students must have 7 digit non-negative long type IDs that start with a non-zero long type");
		}
		if (gpa >= 0.0 && gpa <= 4.0)
		{
			this.gpa = gpa;
		}
		else
		{
			throw new IllegalArgumentException("All salaries must be positive");
		}
	}
	
	/**
	* A constructor with all of the properties set at construction time
	*
	* @param 	fN		The first or given name of the new Student object
	* @param 	lN		The last or family name of the new Student object
	* @param 	mN		The middle name of the new Student object
	* @param 	major	The courtesy major of the new Student object (valid values are "Mr", "Mrs", "Ms", "Miss", or "Dr")
	* @param 	suffix	The name suffix of the new Student object (valid values are "Jr", "II", "III", "IV", or "PhD")
	* @param 	sex		The gender or sex of the new Student object (valid values are "male", "female", and "unspecified")
	* @param 	age		The age in years of the new Student object (age must be a positive integer less than 128)
	* @param 	stuNum	The Student Number of the new Student object (valid Student Numbers are 10 digit numbers beginning with a non-zero long type)
	* @param	major	The job major of the new Student object (valid values are "Trainee", "Analyst", "Programmer", "Manager", or "Director")
	* @param	dept	The organizational collegeDepartment of the new Student object (valid values are "Human Resources", "Coding", "Marketing", or "Sales")
	* @param	gpa	The annual gpa in U.S. dollars for the new Student object.  All salaries must be at least 0.0.
	*
	* @throws	IllegalArgumentException Thrown if the passed in student number is not a 10 digit number beginning with a non-zero long type;
	*			if the job major is not one of "Trainee", "Analyst", "Programmer", "Manage", or "Director";
	*			if the collegeDepartment is not one of "Human Resources", "Coding", "Marketing", or "Sales";
	*			or if the gpa is less than zero
	*/
	public Student(String fN, String lN, String mN, String major, String suffix, String sex, byte age, long stuNum, String chooseMajor, String dept, double gpa) throws IllegalArgumentException
	{
		super(fN, lN, mN, chooseMajor, suffix, sex, age);
		if (stuNum < 1000000000L || stuNum > 9990000000L)
		{
			throw new IllegalArgumentException("All Student Numbers must be 10 digit numbers beginning with a non-zero long type");
		}
		else
		{
			studentNumber = stuNum;
		}
		if (chooseMajor.equals("Trainee") || chooseMajor.equals("Analyst") || chooseMajor.equals("Programmer") || chooseMajor.equals("Manager") || chooseMajor.equals("Director"))
		{
			chooseMajor = major;
		}
		else
		{
			throw new IllegalArgumentException("All Student Job Titles must be one of \"Trainee\", \"Analyst\", \"Programmer\", \"Manager\", or \"Director\"");
		}
		if (dept.equals("Mathematics") || dept.equals("CIT") || dept.equals("Nursing") || dept.equals("English"))
		{
			collegeDepartment = dept;
		}
		else
		{
			throw new IllegalArgumentException("All Student collegeDepartments must be one of \"Human Resources\", \"Coding\", \"Marketing\", or \"Sales\"");
		}
		if (gpa >= 0.0 && gpa <= 4.0)
		{
			this.gpa = gpa;
		}
		else
		{
			throw new IllegalArgumentException("Student object salaries cannot be negative");
		}
	}
	
	/**
	* A set method (mutator) that sets the value of the Student object's Student Number
	*
	* @param stuNum	The Student Number of the new Student object (valid Student Numbers are 10 digit numbers beginning with a non-zero long type)
	* @throws IllegalArgumentException Thrown if the passed in Student Number is not a 10 digit number starting with a non-zero long type
	*/
	public void setStudentNumber(long stuNum)
	{
		if (stuNum < 1000000000L || stuNum > 9990000000L)
				{
					throw new IllegalArgumentException("All Student Numbers must be 10 digit numbers beginning with a non-zero long type");
				}
				else
				{
					studentNumber = stuNum;
		}
	}
	
	/**
	* A set method (mutator) that sets the value of this Student Objects Job Titled (valid values are:  "Trainee", "Analyst", "Programmer", "Manager", "Director")
	*
	* @param major		The Job Title of this Student Object
	*
	* @throws IllegalArgumentException		Thrown if the passed in Job Title is not one of "Trainee", "Analyst", "Programmer", "Manager", "Director"
	*/
	public void setchooseMajor(String major)
	{
		if (major.equals("Trainee") || major.equals("Analyst") || major.equals("Programmer") || major.equals("Manager") || major.equals("Director"))
		{
			chooseMajor = major;
		}
		else
		{
			throw new IllegalArgumentException("All Student Objects must have a major of \"Trainee\", etc.");
		}
	}
	
	/**
	* A set method (mutator) for updating the organizational collegeDepartment for this Student object
	*
	* @param	dept		The organizational collegeDepartment of the new Student object (valid values are "Human Resources", "Coding", "Marketing", or "Sales")
	*
	* @throws	IllegalArgumentException Thrown if the passed in collegeDepartment is not one of "Human Resources", "Coding", "Marketing", or "Sales";
	*/
	public void setcollegeDepartment(String dept)
	{
		if (dept.equals("Mathematics") || dept.equals("CIT") || dept.equals("Nursing") || dept.equals("English"))
		{
			collegeDepartment = dept;
		}
		else
		{
			throw new IllegalArgumentException("All Student collegeDepartments must be one of \"Human Resources\", \"Coding\", \"Marketing\", or \"Sales\"");
		}
	}
	
	/**
	* A set method (mutator) for updating the annual GPA in U.S. dollars for this Student object
	*
	* @param	gpa		The annual gpa in U.S. dollars for the new Student object (valid values cannot be negative)
	*
	* @throws	IllegalArgumentException Thrown if the passed in gpa is less than zero
	*/
	public void setGPA(double gpa)
	{
		if (gpa >= 0.0 && gpa <= 4.0)
		{
			this.gpa = gpa;
		}
		else
		{
			throw new IllegalArgumentException("Student object GPA cannot be negative or bigger than 4.0");
		}
	}
	
	/**
	* A get method (accessor) to retrieve this Student object's Student Number
	*
	* @return The StudentNumber of this Student object
	*/
	public long getStudentNumber()
	{
		return studentNumber;
	}
	
	/**
	* A get method (accessor) to retrieve this Student Object's Job Title
	*
	* @return	The Job Title of this Student Object
	*/
	public String getchooseMajor()
	{
		return chooseMajor;
	}
	
	/**
	* A get method (accessor) to retrieve this Student object's collegeDepartment
	*
	* @return The collegeDepartment of this Student object
	*/
	public String getcollegeDepartment()
	{
		return collegeDepartment;
	}
	
	/**
	* A get method (accessor) to retrieve this Student object's annual GPA
	*
	* @return The annual GPA in U.S. dollars of this Student object
	*/
	public double getGPA()
	{
		return gpa;
	}
}
