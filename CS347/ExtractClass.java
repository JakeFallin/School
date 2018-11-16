class phoneNumber() {
	private String _officeAreaCode;
    private String _officeNumber;

    public phoneNumber(String areaCode, String number) {
    	_officeAreaCode = areaCode;
    	_officeNumber = number;
    }

    public String getPhoneNumber() {
    	return "(" + _officeAreaCode + ") " + _officeNumber;
    }
}

class Person {
    private String _name;
    phoneNumber phoneNumber;

    public Person(String name, String areaCode, String number) {
    	_name = name;
    	phoneNumber = phoneNumber(areaCode, number);
    }

    public String getName() {
        return _name;
    }

    public String getPhoneNumber() {
    	return phoneNumber.getPhoneNumber();
    }
}

