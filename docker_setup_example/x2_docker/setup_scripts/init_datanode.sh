#!/bin/bash




sudo mkdir $PGFILES/datanode

sudo chown -R postgres:postgres $PGFILES/datanode

initdb -D $PGFILES/datanode --nodename dn

sudo -u postgres echo "host all  all    0.0.0.0/0  trust" >> $PGFILES/datanode/pg_hba.conf
sudo -u postgres echo "listen_addresses='*'" >> $PGFILES/datanode/postgresql.conf
sudo -u postgres sed -i "s/^#gtm_host =.*/gtm_host = '$GTM_IP'/" $PGFILES/datanode/postgresql.conf
sudo -u postgres sed -i "s/^#gtm_port =.*/gtm_port = '$GTM_PORT'/" $PGFILES/datanode/postgresql.conf

postgres --datanode -D  $PGFILES/datanode/ -i >$LOG_DIR/logfile_Px_d 2>&1  &

tail -f $LOG_DIR/logfile_Px_d
