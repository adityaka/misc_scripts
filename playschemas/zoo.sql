-- this is a database schema for a zoo operations 
-- a fun excercise in data base related applications
-- for mysql 

-- the existing database will be dropped 
-- WARNING - DATA will be lost 
drop database if exists zoo;
create database zoo;
use zoo;

-- caretakers definition 
create table caretakers (
	id int not null primary key, 
	first_name varchar(100) not null,
	middle_name varchar(100),
	last_name varchar(100) not null,
	date_of_birth date not null,
	address_id int not null,
	phone_id int not null,
	email varchar(250),

	index (address_id),
	index (phone_id),

	foreign key (address_id) references addresses(id)
	on update cascade on delete cascade,
	foreign key (phone_id) references phonenumbers(id) 
	on update cascade on delete cascade 
	
);

-- addresses for the care takers and zoo staff 
create table addresses (
	id int not null primary key,
	house_no varchar(250),
	street varchar(256),
	landmark varchar(256),
	city varchar(100),
	state varchar(100),
	country varchar(100),
	zipcode varchar(20)

);

-- phone numbers data 
create table phonenumbers(
	id int not null primary key, 
	number varchar(50) not null, 
	type  varchar(10) not null
)



-- cages for the animals 
create table cages (
	id int not null primary key,
	length int not null, 
	breadth int not null,
	height int not null, 
);

-- Animal Table definitions
create table animals (
	id int not null primary key, 
	name varchar(100) not null,
	age int not null,
	date_of_birth date,
	cageid int not null 
);