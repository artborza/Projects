public class Database extends Strategy{
    private String sort;
    private String search;

    public String getSort() {
        return sort;
    }

    public void setSort(String sort) {
        this.sort = sort;
        System.out.println(sort);
    }

    public String getSearch() {
        return search;
    }

    public void setSearch(String search) {
        this.search = search;
    }
}
