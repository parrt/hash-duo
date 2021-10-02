# hash-duo

Explore building a hash table with two different hash functions that balances chain length.

There is a really cool article called [Don't Throw Out Your Algorithms Book Just Yet: Classical Data Structures That Can Outperform Learned Indexes](https://dawn.cs.stanford.edu/2018/01/11/index-baselines/) that described two hash mechanisms I had not heard of. The Cuckhoo hash is unappealing to me so I'm going to try the other which is simply to keep two tables in the hash and add keys to the bucket with the shorter length. The description from another good article, [The Power of Two Random Choices: A Survey of Techniques and Results](https://www.eecs.harvard.edu/~michaelm/postscripts/handbook2001.pdf), says it all:

>	"*...suppose that we use two perfectly random hash functions. When inserting a key, we apply both hash functions to determine the two possible table entries where the key can be inserted. Then, of the two possible entries, we add the key to the shorter of the two chains. To search for an element, we have to search through the chains at the two entries given by both hash functions. If n keys are sequentially inserted into the table, the length of the longest chain is Θ(log log n) with high probability, implying that the maximum time needed to search the hash table is Θ(log log n) with high probability.*"
