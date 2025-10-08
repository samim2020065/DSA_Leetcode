class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	vector<int>v(m);
	for(int i=0;i<m;i++){
		v[i]=nums1[i];
	}
	int x=0,i=0,j=0;
	while(i<m&&j<n){
		if(v[i]<=nums2[j]){
			nums1[x]=v[i];
			i++;
		}
		else{
			nums1[x]=nums2[j];
			j++;
		}
		x++;
	}
	while(i<m){
		nums1[x]=v[i];
		i++;
		x++;
	}
	while(j<n){
		nums1[x]=nums2[j];
		j++;
		x++;
	}
	
}
};