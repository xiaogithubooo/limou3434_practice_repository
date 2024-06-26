"""empty message

Revision ID: ea1bf3cd8679
Revises: 5ff1d7c117cf
Create Date: 2024-03-31 15:52:01.351566

"""
from alembic import op
import sqlalchemy as sa
from sqlalchemy.dialects import mysql

# revision identifiers, used by Alembic.
revision = 'ea1bf3cd8679'
down_revision = '5ff1d7c117cf'
branch_labels = None
depends_on = None


def upgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    with op.batch_alter_table('email_captcha', schema=None) as batch_op:
        batch_op.add_column(sa.Column('email', sa.String(length=100), nullable=False))
        batch_op.drop_column('username')

    # ### end Alembic commands ###


def downgrade():
    # ### commands auto generated by Alembic - please adjust! ###
    with op.batch_alter_table('email_captcha', schema=None) as batch_op:
        batch_op.add_column(sa.Column('username', mysql.VARCHAR(collation='utf8mb4_unicode_ci', length=100), nullable=False))
        batch_op.drop_column('email')

    # ### end Alembic commands ###
