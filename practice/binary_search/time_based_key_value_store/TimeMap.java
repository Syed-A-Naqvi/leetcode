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

    public String get(String key, int timestamp) {

        ArrayList<Pair> values = timedItems.get(key);
        if (values == null) {
            return "";
        }
        
        int l = 0, m = 0, r = values.size()-1;

        if (values.get(l).time() > timestamp) {
            return "";
        }
        else if (values.get(r).time() <= timestamp) {
            return values.get(r).value();
        }

        while(l < r) {
            m = (l + r) / 2;

            if ((values.get(m).time() == timestamp) || (m == l)) {
                return values.get(m).value();
            }
            else if (values.get(m).time() < timestamp) {
                l = m;
            }
            else if (values.get(m).time() > timestamp) {
                r = m;
            }
        }

        return "something went wrong.";
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