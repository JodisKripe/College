class cusExec extends Throwable{
    String dmesg;
    cusExec(String dmesg){
        this.dmesg = dmesg;
    }
    @Override
    public String toString() {
        return dmesg;
    }
}

public class customException {
    public static void main(String args[]){
        try{
            throw new cusExec("O mama!");
        } catch(cusExec e){
            System.out.println(e);
        }
        finally{
            System.out.println("Lessgo!!");
        }
    }
    }
