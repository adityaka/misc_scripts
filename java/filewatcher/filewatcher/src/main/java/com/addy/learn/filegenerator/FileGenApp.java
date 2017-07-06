package  com.addy.learn.filegenerator;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class FileGenApp extends Thread {
    public static final int NUMBER_OF_FILES = 1000;
    public static final String FILE_NAME_PREFIX = "FileGen"
    public static String[] CONTENT_SAMPLES = new String[] {
            "Quick brown fox jumped over the lazy dog",
            "Quick brown dog jumped over the cat",
            "Quick brown cat jumped over a frog",
            "Quick brown frog jumped over a hen",
            "Lazy brown hen slept","Quick black cat ate the hen",
            "Quick black cat got lazy",
            "Lazy black cat slept",
            "Quick brown dog ate the lazy cat",
            "Quick brown dog got lazy",
            "Lazy brown dog slept",
            "Quick brown fox kicked and jumped over the lazy dog"
    };

    private List<String> fileList;
    private String rootDirectory;
    private String nextFileName;
    private Random rand;

    private  String getNextFileName(){
        String fileName = FileGenApp.FILE_NAME_PREFIX + Integer.toString(rand.nextInt(NUMBER_OF_FILES +1) * rand.nextInt(300));
        return fileName;
    }

    public FileGenApp(){
        fileList = new ArrayList<>();
        rand = new Random();
    }
    public FileGenApp(String root){
        rootDirectory = root;
    }

    public List<String> getFileList() {
        return fileList;
    }

    public String getRootDirectory() {
        return rootDirectory;
    }

    public void setRootDirectory(String rootDirectory) {
        this.rootDirectory = rootDirectory;
    }
}