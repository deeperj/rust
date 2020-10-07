class Example {
   static void main(String[] args) {
      // Creating a generic List collection
      List<String> list = new ArrayList<String>();
      list.add("First String");
      list.add("Second String");
      list.add("Third String");
		
      for(String str : list) {
         println(str);
      }
   } 
}