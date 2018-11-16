import java.sql.*;

public class db {
    // JDBC driver name and database URL
    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver"; 
    static final String DB_URL = "jdbc:mysql://localhost/test";
    //  Database credentials
    static final String USER = "root";
    static final String PASS = "HJbailey88";

    public static void question(Connection conn, String sql, int num) {
      try {
        System.out.println("\nQuestion " + num);
        Statement s = conn.createStatement();
        ResultSet rs = s.executeQuery(sql);
        while(rs.next()) {
          System.out.println(rs.getString("driver_name"));
        }
        rs.close();
        s.close();
      } catch(SQLException e) {
        e.printStackTrace();
      }
    }

    public static void main(String[] args) {

    Connection conn = null;
    Statement stmt = null;

    try {
      //STEP 1: Register JDBC driver
      Class.forName("com.mysql.jdbc.Driver");
      //STEP 2: Open a connection
      System.out.println("\nConnecting to database...");
      conn = DriverManager.getConnection(DB_URL, USER, PASS);

    } catch (Exception e) {
      System.err.println("Error: " + e);
      System.err.println ("Cannot connect to database server");
   
    } finally {
      if (conn != null) {
        try {
          
          System.out.println("Connecting!\n");
          stmt = conn.createStatement();
          String sql = "";

          //database setup
          sql = "Drop database if exists VehicleOffice";
          stmt.executeUpdate(sql);

          sql = "create Database VehicleOffice";
          stmt.executeUpdate(sql);
          System.out.println("\nCreated Database VehicleOffice");

          sql = "use VehicleOffice";
          stmt.executeUpdate(sql);

          //table creation
          sql = "create table branch(branch_id integer not null PRIMARY KEY,"
            + "branch_name varchar(20) not null,"
            + "branch_addr varchar(50)," 
            + "branch_city varchar(20) not null,"
            + "branch_phone integer)";
          stmt.executeUpdate(sql);

          sql = "create table driver(driver_ssn integer not null PRIMARY KEY," 
            + "driver_name varchar(20) not null,"
            + "driver_addr varchar(50) not null," 
            + "driver_city varchar(20) not null,"
            + "driver_birthdate date not null," 
            + "driver_phone integer)";
          stmt.executeUpdate(sql);

          sql = "CREATE TABLE license(license_no INTEGER not null PRIMARY KEY,"
            + "driver_ssn INTEGER,"
            + "license_type CHAR,"
            + "license_class INTEGER," 
            + "license_expiry DATE," 
            + "issue_date DATE," 
            + "branch_id INTEGER," 
            + "FOREIGN KEY (driver_ssn) REFERENCES driver(driver_ssn));";
          stmt.executeUpdate(sql);

          sql = "CREATE TABLE exam(driver_ssn integer not null," 
            + "branch_id integer not null,"
            + "exam_date DATE,"
            + "exam_type CHAR,"
            + "exam_score INTEGER,"
            + "FOREIGN KEY (driver_ssn) REFERENCES driver(driver_ssn),"
            + "FOREIGN KEY (branch_id) REFERENCES branch(branch_id),"
            + "PRIMARY KEY (driver_ssn, branch_id, exam_date));";
          stmt.executeUpdate(sql);

          //insert values
          sql = "insert into branch values(10, 'Main', '1234 Main St.', 'Hoboken', 5551234)";
          stmt.executeUpdate(sql);
          sql = "insert into branch values(20, 'NYC', '23 No.3 Road', 'NYC', 5552331)";
          stmt.executeUpdate(sql);
          sql = "insert into branch values(30, 'West Creek', '251 Creek Rd.', 'Newark', 5552511)";
          stmt.executeUpdate(sql);
          sql = "insert into branch values(40, 'Blenheim', '1342 W.22 Ave.', 'Princeton', 5551342)";
          stmt.executeUpdate(sql);

          sql = "insert into driver values(11111111, 'Bob Smith', '111 E. 11 St.', 'Hoboken', '1975-01-01', 5551111)";
          stmt.executeUpdate(sql);
          sql = "insert into driver values(22222222, 'John Walters', '222 E. 22 St.', 'Princeton', '1976-02-02', 5552222)";
          stmt.executeUpdate(sql);
          sql = "insert into driver values(33333333, 'Troy Rops', '333 W.33 Ave', 'NYC', '1974-04-04', 5553333)";
          stmt.executeUpdate(sql);
          sql = "insert into driver values(44444444, 'Kevin Mark', '444 E.4 Ave.', 'Hoboken', '1976-02-02', 5554444)";
          stmt.executeUpdate(sql);

          sql = "insert into license values(1, 11111111, 'D', 5, '2022-05-04', '2017-05-25', 20)";
          stmt.executeUpdate(sql);
          sql = "insert into license values(2, 22222222, 'D', 5, '2023-08-29', '2016-08-29', 40)";
          stmt.executeUpdate(sql);
          sql = "insert into license values(3, 33333333, 'L', 5, '2022-12-27', '2017-06-27', 20)";
          stmt.executeUpdate(sql);
          sql = "insert into license values(4, 44444444, 'D', 5, '2022-08-30', '2017-08-30', 40)";
          stmt.executeUpdate(sql);

          sql = "insert into exam values(11111111, 20, '2017-05-25', 'D', 79)";
          stmt.executeUpdate(sql);
          sql = "insert into exam values(11111111, 20, '2017-12-02', 'L', 67)";
          stmt.executeUpdate(sql);
          sql = "insert into exam values(22222222, 30, '2016-05-06', 'L', 25)";
          stmt.executeUpdate(sql);
          sql = "insert into exam values(22222222, 40, '2016-06-10', 'L', 51)";
          stmt.executeUpdate(sql);
          sql = "insert into exam values(22222222, 40, '2016-08-29', 'D', 81)";
          stmt.executeUpdate(sql);
          sql = "insert into exam values(33333333, 10, '2017-07-07', 'L', 45)";
          stmt.executeUpdate(sql);
          sql = "insert into exam values(33333333, 20, '2017-06-27', 'L', 49)";
          stmt.executeUpdate(sql);
          sql = "insert into exam values(33333333, 20, '2017-07-27', 'L', 61)";
          stmt.executeUpdate(sql);
          sql = "insert into exam values(44444444, 10, '2017-07-27', 'L', 71)";
          stmt.executeUpdate(sql);
          sql = "insert into exam values(44444444, 20, '2017-08-30', 'L', 62)";
          stmt.executeUpdate(sql);
          //select
          Statement s = conn.createStatement();
          s.executeQuery("select branch_id, branch_name, branch_addr from branch");
          ResultSet rs = s.getResultSet();
          int count = 0;
          while(rs.next()) {
            int idVal = rs.getInt("branch_id");
            String nameVal = rs.getString("branch_name");
            String addrVal = rs.getString("branch_addr");
            System.out.println("branch id = " + idVal + ", name = " + nameVal + ", address = " + addrVal);
            ++count;
          }
          rs.close();
          s.close();
          System.out.println("Retrieved " + count + " rows");

          //question1
          String q1 = "Select driver_name "
            + "from driver D, license L, branch B "
            + "where D.driver_ssn = L.driver_ssn " 
            + "and B.branch_id = L.branch_id "
            + "and branch_name='NYC';";
          question(conn, q1, 1);

          //question2
          String q2 = "Select distinct driver_name "
            + "from driver D, license L "
            + "where D.driver_ssn = L.driver_ssn "
            + "and L.license_expiry<='2022-12-31';";
          question(conn, q2, 2);

          String q3 = "Select distinct D.driver_name "
            + "from exam E, exam E1, driver D " 
            + "where E.branch_id = E1.branch_id "
            + "and E.driver_ssn = E1.driver_ssn "
            + "and E.exam_date != E1.exam_date "
            + "and E1.exam_type = E.exam_type "
            + "and E.driver_ssn = D.driver_ssn;"; 
          question(conn, q3, 3);





















          

          String q4 = "Select distinct driver_name "
            + "from driver "
            + "where driver_name ='Kevin Mark' and " 
            + "driver.driver_ssn not in ( "
            + "select distinct E.driver_ssn "
            + "from exam E, exam E1 "
            + "where E.driver_ssn = E1.driver_ssn " 
            + "and E.exam_date > E1.exam_date "
            + "and E.exam_type = E1.exam_type "
            + "and E.exam_score > E1.exam_score);";
          question(conn, q4, 4); 
          conn.close ();
          System.out.println ("\nDatabase connection terminated\n");
        }
        catch (Exception e) { /* ignore close errors */ }
        }
      }
    }
}
