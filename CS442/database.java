import java.sql.*;
import com.mysql.jdbc.Driver;

public class database {
    // JDBC driver name and database URL
    static final String JDBC_DRIVER = "com.mysql.jdbc.Driver"; 
    static final String DB_URL = "jdbc:mysql://localhost/test";
    //  Database credentials
    static final String USER = "root";
    static final String PASS = "HJbailey88";

    public static void question(Connection conn, String sql, int num, String gs) {
      try {
        System.out.println("\nQuestion " + num);
        Statement s = conn.createStatement();
        ResultSet rs = s.executeQuery(sql);
        while(rs.next()) {
          if(num == 3) {
            System.out.println("sid= " + rs.getString("sid") + " sname= " + rs.getString("sname") + " rating= " + rs.getString("rating") + " age= " + rs.getString("age"));
          } else {
            System.out.println(gs + "= " + rs.getString(gs));
          }
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
      e.printStackTrace();
      System.err.println ("Cannot connect to database server");
   
    } finally {
      if (conn != null) {
        try {
          
          System.out.println("Connecting!\n");
          stmt = conn.createStatement();
          String sql = "";

          //database setup
          sql = "Drop database if exists BoatRental";
          stmt.executeUpdate(sql);

          sql = "create Database BoatRental";
          stmt.executeUpdate(sql);
          System.out.println("\nCreated 1Database BoatRental");

          sql = "use BoatRental";
          stmt.executeUpdate(sql);

          System.out.println("\nCreate");

          //table creation
          sql = "create table Sailor(sid integer not null PRIMARY KEY,"
            + "sname varchar(20) not null,"
            + "rating real," 
            + "age integer not null)";
          stmt.executeUpdate(sql);

          sql = "create table Boats(bid integer not null PRIMARY KEY," 
            + "bname varchar(40) not null,"
            + "color varchar(40) not null)";
          stmt.executeUpdate(sql);

          sql = "CREATE TABLE Reserves(sid integer not null,"
            + "bid integer not null,"
            + "day date not null,"
            + "FOREIGN KEY (sid) REFERENCES Sailor(sid),"
            + "FOREIGN KEY (bid) REFERENCES Boats(bid),"
            + "PRIMARY KEY (sid, bid, day))";
          stmt.executeUpdate(sql);

                             System.out.println("\nInsert");

          //insert values
          sql = "insert into Sailor values(22, 'Dustin', 7, 45)";
          stmt.executeUpdate(sql);
          sql = "insert into Sailor values(29, 'Brutus', 1, 33)";
          stmt.executeUpdate(sql);
          sql = "insert into Sailor values(31, 'Lubber', 8, 55)";
          stmt.executeUpdate(sql);
          sql = "insert into Sailor values(32, 'Andy', 8, 26)";
          stmt.executeUpdate(sql);
          sql = "insert into Sailor values(58, 'Rusty', 10, 35)";
          stmt.executeUpdate(sql);
          sql = "insert into Sailor values(64, 'Horatio', 7, 35)";
          stmt.executeUpdate(sql);
          sql = "insert into Sailor values(71, 'Zorba', 20, 18)";
          stmt.executeUpdate(sql);
          sql = "insert into Sailor values(74, 'Horatio', 9, 35)";
          stmt.executeUpdate(sql);
          
          sql = "insert into Boats values(101, 'Interlake', 'Blue')";
          stmt.executeUpdate(sql);
          sql = "insert into Boats values(102, 'Interlake', 'Red')";
          stmt.executeUpdate(sql);
          sql = "insert into Boats values(103, 'Clipper', 'Green')";
          stmt.executeUpdate(sql);
          sql = "insert into Boats values(104, 'Marine', 'Red')";
          stmt.executeUpdate(sql);
          
          sql = "insert into Reserves values(22, 101, '2018-10-10')";
          stmt.executeUpdate(sql);
          sql = "insert into Reserves values(22, 102, '2018-10-10')";
          stmt.executeUpdate(sql);
          sql = "insert into Reserves values(22, 103, '2017-10-08')";
          stmt.executeUpdate(sql);
          sql = "insert into Reserves values(22, 104, '2017-10-09')";
          stmt.executeUpdate(sql);
          sql = "insert into Reserves values(31, 102, '2018-11-10')";
          stmt.executeUpdate(sql);
          sql = "insert into Reserves values(31, 103, '2018-11-06')";
          stmt.executeUpdate(sql);
          sql = "insert into Reserves values(31, 104, '2018-11-12')";
          stmt.executeUpdate(sql);
          sql = "insert into Reserves values(64, 101, '2018-09-05')";
          stmt.executeUpdate(sql);
          sql = "insert into Reserves values(64, 102, '2018-09-08')";
          stmt.executeUpdate(sql);
          sql = "insert into Reserves values(74, 103, '2018-09-08')";
          stmt.executeUpdate(sql);

          System.out.println("\nSelect");
          //question1
          String q1 = "Select S.sid From Sailor S, Reserves R, Boats B, Where B.color = 'red' And S.sid = R.sid And B.bid = R.bid And S.sid Not In (Select S.sid From Sailor S1, Reserves R1, Boats B Where S1.sid = R1.sid And B1.bid = R1.bid And B1.color = 'green')";
          question(conn, q1, 1, "sid");

          //question2
          String q2 = "Select S.sname From Sailor S where S.sid Not In (Select S1.sid From Sailor S1, Reserves R, Boats B Where B.color='red' And B.bid = R.bid And S1.sid = R.sid)";
          question(conn, q2, 2, "sname");

          String q3 = "Select * From Sailor Where rating > All (Select rating from Sailor Where sname ='Horatio')";
          question(conn, q3, 3, "3");

          String q4 = "Select S.sname From Sailor S, Reserves R Where S.sid = R.sid Group By S.sid Having Count(Distinct bid) = (Select Count(Distinct bid) as mycount From Boats)";
          question(conn, q4, 4, "sname"); 

          System.out.println("\nComplete");

          // String q5 = "SELECT sname 
          //           FROM
          //           (SELECT SailorReserve.sname, SailorReserve.sid, COUNT(SailorReserve.sid) as ReserveCount
          //           FROM (SELECT DISTINCT S.sid, S.sname, R.Bid, R.Day
          //                 FROM Sailor S, Reserves R
          //                 WHERE S.sid = R.sid
          //                  AND S.sid IN (SELECT R.sid
          //                                 FROM Reserves R, Boats B
          //                                 WHERE R.bid = B.bid
          //                                  AND B.color = 'Red')) as SailorReserve
          //           GROUP BY SailorReserve.sid, SailorReserve.sname
          //           ORDER BY ReserveCount DESC) as Count
          //           WHERE Count.ReserveCount = (SELECT Count.ReserveCount
          //                                FROM (SELECT SailorReserve.sname, SailorReserve.sid, COUNT(SailorReserve.sid) as ReserveCount
          //                                       FROM (SELECT DISTINCT S.sid, S.sname, R.Bid, R.Day
          //                                             FROM Sailor S, Reserves R
          //                                             WHERE S.sid = R.sid
          //                                              AND S.sid IN (SELECT R.sid
          //                                                             FROM Reserves R, Boats B
          //                                                             WHERE R.bid = B.bid
          //                                                              AND B.color = 'Red')) as SailorReserve
          //                                       GROUP BY SailorReserve.sid, SailorReserve.sname
          //                                       ORDER BY ReserveCount DESC) as Count
          //                                ORDER BY Count.ReserveCount DESC
          //                                LIMIT 1)");
          // question(conn, q5, 5, "sname");


          conn.close();
          System.out.println ("\nDatabase connection terminated\n");
        }
        catch (Exception e) { /* ignore close errors */ }
        }
      }
    }
}
