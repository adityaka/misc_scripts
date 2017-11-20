# See https://docs.getchef.com/config_rb_knife.html for more information on knife configuration options

current_dir = File.dirname(__FILE__)
log_level                :info
log_location             STDOUT
node_name                "addy"
client_key               "#{current_dir}/addy.pem"
chef_server_url          "https://chef-server.rqyn1w3kxfveddrxzhhpn2guih.tx.internal.cloudapp.net/organizations/addyazureorg"
cookbook_path            ["#{current_dir}/../cookbooks"]
