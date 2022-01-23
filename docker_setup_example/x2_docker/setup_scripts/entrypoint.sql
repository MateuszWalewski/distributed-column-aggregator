CREATE NODE dn1 WITH (TYPE='datanode', PORT=5444, HOST="192.168.1.15");
CREATE NODE dn2 WITH (TYPE='datanode', PORT=5445, HOST="192.168.1.15");
CREATE NODE dn3 WITH (TYPE='datanode', PORT=5446, HOST="192.168.1.15");
CREATE NODE dn4 WITH (TYPE='datanode', PORT=5447, HOST="192.168.1.15");

select pgxc_pool_reload();
select * from pgxc_node;

create table test (a int);
insert into test  SELECT generate_series(1, 100);
