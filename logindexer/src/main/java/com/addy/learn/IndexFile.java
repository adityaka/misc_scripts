package com.addy.learn;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Path;
import java.util.Iterator;

public class IndexFile implements Iterable<IndexRecord> {
    private File indexFile;
    JSONObject indexRoot;

    public IndexFile(String path) throws FileNotFoundException,ParseException, IOException {
        indexFile = new File(path);
        indexFile.
    }

    public IndexRecord getNextRecord() {

    }

    @Override
    public Iterator<IndexRecord> iterator() {
        return getNextRecord();
    }
}
