class Solution {
    public double average(int[] salary) {
        Arrays.sort(salary);
        double sum = 0.0;
        int l = salary.length;
        for (int x = 1; x < l - 1; x++) {
            sum += salary[x];
        }
        return sum / (l - 2);
    }
}