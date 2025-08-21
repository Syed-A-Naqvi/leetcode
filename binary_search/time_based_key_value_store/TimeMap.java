package binary_search.time_based_key_value_store;

import java.util.ArrayList;
import java.util.HashMap;

public class TimeMap {

    HashMap<String, ArrayList<Pair>> timedItems;

    public TimeMap() {
        this.timedItems = new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {

        if (this.timedItems.get(key) != null) {
            this.timedItems.get(key).add(new Pair(value, timestamp));
        }
        else {
            ArrayList<Pair> temp = new ArrayList<>();
            temp.add(new Pair(value, timestamp));
            this.timedItems.put(key, temp);
        }
    }

    public void get(String key, int timestamp) {
        ArrayList<Pair> values = timedItems.get(key);

        int l = 0, m = 0, r = values.size()-1;

        while(l <= r) {
            m = (l + r) / 2;

            if (values.get(m) < values )
        }
    }
}

class Pair {

    private final String value;
    private final int timeStamp;

    public Pair(String v, int t) {
        this.value = v;
        this.timeStamp = t;
    }

    public int time() {
        return timeStamp;
    }
    public String value() {
        return value;
    }
    
}